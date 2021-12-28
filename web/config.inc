<?php


// Database config
define('DB_NAME', $_ENV['MYSQL_DATABASE'] ?? 'main');
define('DB_USER', $_ENV['MYSQL_USER'] ?? 'main');
define('DB_PASS', $_ENV['MYSQL_PASSWORD'] ?? 'main');
define(
    'DB_HOST',
    $_ENV['PROJECT_NAME'] ? $_ENV['PROJECT_NAME'] . '-mysql' : 'localhost'
);
const DB_CHARSET = 'utf8';
const DB_PORT = 3306;

// Memcache config
define(
    'MEMCACHE_HOST',
    $_ENV['PROJECT_NAME'] ? $_ENV['PROJECT_NAME'] . '-memcache' : 'localhost'
);
const MEMCACHE_PORT = 11211;
const MEMCACHE_PERIOD = 60;

// Base url for parsed site
const PARSER_BASE_URL = 'http://www.world-art.ru/cinema/';
// Items per query on top rated
const PARSER_ITEMS_PER_QUERY = 10;
// Url for full film information
const PARSER_FILM_URL = 'cinema.php?id=%d';
// Url for history position
const PARSER_FILM_HISTORY = 'votes_history.php?id=%d';

// CLI key for calling parser via cron
define('CRON_KEY', $_ENV['CRON_KEY'] ?? '111');

// Cache directory
const CACHE_PARSER_DIRECTORY = __DIR__ . '/cache/';
// Parser files cache period, in seconds
const CACHE_PARSER_PERIOD = 3600 * 24 * 7;

// Images
const IMAGE_DIRECTORY = __DIR__ . '/images/';
// HTML templates
const TEMPLATE_DIRECTORY = __DIR__ . '/tpl/';
// images web
const WEB_IMAGE_DIRECTORY = '/images/';
