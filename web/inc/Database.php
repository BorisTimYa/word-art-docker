<?php


namespace Db;

use Memcached;
use mysqli;
use Exception;

/**
 * Class Database
 *
 * @package Db
 */
class Database extends mysqli
{

    /**
     * @var Memcached
     */
    private Memcached $memcache;

    /**
     * Database constructor.
     *
     * @throws Exception
     */
    public function __construct()
    {
        @parent::__construct(DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT);
        if ($this->connect_errno) {
            throw new Exception("Database error: " . $this->connect_error);
        }
        $this->set_charset(DB_CHARSET);

        $this->memcache = new Memcached();
        $this->memcache->addServer(MEMCACHE_HOST, MEMCACHE_PORT);
        //        $this->memcache->connect(MEMCACHE_HOST, MEMCACHE_PORT);
    }

    /**
     * @param string $sql
     * @param int $cachePeriod
     *
     * @return array
     */
    public function getArray(
        string $sql,
        int $cachePeriod = MEMCACHE_PERIOD
    ): array {
        $key = md5($sql);
        if (!$result = $this->memcache->get($key)) {
            $query = $this->query($sql);
            if ($query->num_rows) {
                $result = $query->fetch_all(MYSQLI_ASSOC);
                $this->memcache->set($key, $result, $cachePeriod);
            }
        }

        return $result;
    }
    //    public function getArray(
    //        string $sql,
    //        int $cachePeriod = MEMCACHE_PERIOD
    //    ): array {
    //        $result = [];
    //        $query = $this->query($sql);
    //        if ($query->num_rows) {
    //            $result = $query->fetch_all(MYSQLI_ASSOC);
    //        }
    //
    //        return $result;
    //    }
}