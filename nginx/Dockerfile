FROM daocloud.io/nginx:alpine

#vbox共享文件夹用户设置（window-virtualbox-centos-docker）
#RUN addgroup -g 983 vboxsf
#RUN addgroup nginx vboxsf

#设置中国时区
RUN apk add tzdata
RUN cp /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
RUN apk del tzdata
