server {
    listen  80;
    server_name  wowtest.local;
    charset     utf-8;

    access_log /var/log/nginx/wowtest.access.log main;
    error_log  /var/log/nginx/wowtest.error.log debug;

	#http://wowtest.local/ondoor代理到http://wowtest.local
	#location ^~ /ondoor/ {
	#	proxy_pass http://127.0.0.1;
	#	rewrite ^/ondoor/(.*)$ /$1 break;
	#}

	#http://wowtest.local/ondoor/admin代理到http://wowtest.local:8080
	#location ^~ /ondoor/admin/ {
	#	proxy_pass http://127.0.0.1:8080;
	#	rewrite ^/ondoor/admin/(.*)$ /$1 break;
	#}
	
	#管理后台的配置
	location ^~ /ondoor/admin {
        index index.shtml index.html;
        try_files $uri /index.html;
    }

    location ~ /ondoor/admin/index.*$ {
        rewrite ^/index.*$ /index.html break;
    }

    location ~ /ondoor/admin/login$ {
        rewrite ^/login /index.html break;
    }

    location ~* ^/ondoor/admin/(css|img|js|flv|swf|download)/(.+)$ {
        root /source/ondoorAdmin/local;
    }
	
	#api的配置
    location /ondoor/ {
	    root /source/ondoorForum/public
        try_files $uri $uri/ /index.php?$query_string;
    }

    location ~ \.php {
	    root /source/ondoorForum/public
		
        fastcgi_pass  fpm:9000;
        fastcgi_index /index.php;

        include fastcgi_params;
        fastcgi_split_path_info       ^(.+\.php)(/.+)$;
        fastcgi_param PATH_INFO       $fastcgi_path_info;
        fastcgi_param PATH_TRANSLATED $document_root$fastcgi_path_info;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
    }

    location ~ /\.ht {
        deny all;
    }
}
