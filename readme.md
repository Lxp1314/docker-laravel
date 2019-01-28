### php
php在39服务器无法编译，挪到了在daocloud编译镜像，服务器直接拉取

### node镜像编译和运行
编译镜像：在app/目录下，运行
```
docker build -t node-apidoc ./node/
```
即可生成node-apidoc镜像

直接运行命令：
```
docker run -it --rm -v /share/source:/source --workdir /source/laravel51  node-apidoc  apidoc -i app/Http/Controllers/ -o ../apidoc/laravel51 -f ".*\\.php$"
```
进入容器
```
docker run -it --rm -v /share/source:/source  node-apidoc sh
```
切换到/source/laravel51/目录（laravel51项目，apidoc.json在此根目录），运行
```
apidoc -i app/Http/Controllers/ -o ../apidoc/laravel51 -f ".*\\.php$"
```
-i Input / source dirname. Location of your project files.（我只生成/app/Http/Controllers下面的文件）
-o Output dirname.（把生成的api文档放到哪个目录，示例放到了/source/apidoc/laravel51文件夹下）
-f 遍历的文件类型

