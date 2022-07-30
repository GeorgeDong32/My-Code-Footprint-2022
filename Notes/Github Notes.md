# Github Notes

[TOC]

## Git 使用

### git 创建:

git init
git branch -M （分支名）
git remote add origin （仓库ssh）
git add .
git commit -m "标注内容"
git push -u origin main

### git 更新：

git add .
git commit -m "提交备注"（必要）
git commit "文件名"//单独提交某文件(选)
git push -u origin （分支名）（第一次必须）
git push -u (第二次)

## Github Pull Requests

> 拉取请求，提交代码的同时不影响原分支，例如向开源项目贡献代码，开发项目时独立出开发分支便于回滚，完成后再合并(merge)

### 对自己的仓库进行`Pull Requests`

* 新建分支
* 提交代码
* new pull requests
* merge 到想要的分支

## Github加速

### hosts修改

````hosts
# GitHub Start 
140.82.113.3       github.com
140.82.114.20      gist.github.com
151.101.184.133    assets-cdn.github.com
151.101.184.133    raw.githubusercontent.com
199.232.28.133     raw.githubusercontent.com 
151.101.184.133    gist.githubusercontent.com
151.101.184.133    cloud.githubusercontent.com
151.101.184.133    camo.githubusercontent.com
199.232.96.133     avatars.githubusercontent.com
151.101.184.133    avatars0.githubusercontent.com
199.232.68.133     avatars0.githubusercontent.com
199.232.28.133     avatars0.githubusercontent.com 
199.232.28.133     avatars1.githubusercontent.com
151.101.184.133    avatars1.githubusercontent.com
151.101.108.133    avatars1.githubusercontent.com
151.101.184.133    avatars2.githubusercontent.com
199.232.28.133     avatars2.githubusercontent.com
151.101.184.133    avatars3.githubusercontent.com
199.232.68.133     avatars3.githubusercontent.com
151.101.184.133    avatars4.githubusercontent.com
199.232.68.133     avatars4.githubusercontent.com
151.101.184.133    avatars5.githubusercontent.com
199.232.68.133     avatars5.githubusercontent.com
151.101.184.133    avatars6.githubusercontent.com
199.232.68.133     avatars6.githubusercontent.com
151.101.184.133    avatars7.githubusercontent.com
199.232.68.133     avatars7.githubusercontent.com
151.101.184.133    avatars8.githubusercontent.com
199.232.68.133     avatars8.githubusercontent.com
199.232.96.133     avatars9.githubusercontent.com
# GitHub End
````

## Licenses 开源证书

### 证书区别

<img src="Pics\开源证书选择.jpg" alt="img" style="zoom:80%;">


## GitHub仓库语言占比

仓库的语言占比经测试是按照对应语言的文件大小计算,而非完全依照行数计算
