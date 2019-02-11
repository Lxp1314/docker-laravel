FROM node:8-alpine

#vbox共享文件夹用户设置（window-virtualbox-centos-docker）
#RUN addgroup -g 983 vboxsf
#RUN addgroup node vboxsf

#设置中国时区
RUN apk add tzdata
RUN cp /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
RUN apk del tzdata

#安装apidock
RUN npm install apidoc -g
