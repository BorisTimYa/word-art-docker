FROM mysql:8.0.27
COPY docker/word-art.sql /tmp/word-art.sql
RUN mysql -p$MYSQL_PASSWORD -u $MYSQL_USER $MYSQL_DATABASE < /tmp/word-art.sql
#RUN rm /tmp/word-art.sql