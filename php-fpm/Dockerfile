FROM daocloud.io/wuyun_1/php-fpm-7_2-alpine:latest

#vbox共享文件夹用户设置
RUN addgroup -g 983 vboxsf
RUN addgroup www-data vboxsf

#设置中国时区
RUN apk add tzdata
RUN cp /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
RUN apk del tzdata

WORKDIR /source
