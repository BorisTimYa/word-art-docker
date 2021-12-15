FROM php:8.1-fpm
RUN apt-get update && apt-get install -y libpq-dev git unzip zlib1g-dev libpng-dev libmemcached-dev \
    && pecl install memcached \
    && docker-php-ext-enable memcached \
    && docker-php-ext-install mysqli \
    && docker-php-ext-enable mysqli
