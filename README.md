# 动物园管理系统

## 文件说明

1. animal.cpp为主程序
2. Time.h为获取动物喂养时间的头文件
3. README.md为说明文档
4. animal.txt为记录下来的动物信息
5. animal.exe为可执行程序

## 基本功能

### 大功能介绍

动物园喂食管理、动物分类系统、动物健康情况、动物行为；

***

- **动物园喂食**考虑到动物的饥饿程度：

> 如果8小时未进食，判断为饥饿，每次需要有更新进食时间的按键。
>
> 获取当前时间：通过时间戳转化为标准时间

- **动物分类**通过动物分类学中的**纲**：

> 考虑到有70多种纲，现在按照生活环境分为：陆生动物，水生动物，两栖动物；
>
> 按等级分可分为两种：高等动物，低等动物；
>
> 按食性可分为四种：肉食性动物、植食性动物、腐食性动物、杂食性动物；
>
> 按哺乳方式可分为两种：哺乳动物、非哺乳动物。

- **动物健康**考虑到动物的喂食情况：

> 长期未喂食的动物被添加到紧急提醒栏目中；
>
> 动物的健康情况可以被添加，修改；

- **动物行为**不同动物有不同的行为。

***

### 具体小功能

1. 添加动物
2. 显示所添加的所有动物
3. 改变动物信息
4. 根据动物名找动物
5. 删除动物
6. 显示出哪些动物需要喂食
7. 保存数据
8. 退出系统

## 具体实现

参考实验报告