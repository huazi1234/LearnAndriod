
adb shell cd进包名路径提示没有访问权限的解决办法
原创Likianta Me 最后发布于2017-12-01 21:00:59 阅读数 3563  收藏
展开
adb是Android SDK自带的调试工具，使用前需要先在Windows的环境变量中添加它的路径（本篇文章略过）。

问题描述
在Android Studio里面运行模拟器，然后打开 开始菜单 - CMD 输入adb shell，并访问apk路径中的数据库文件：





发现被拒绝访问。

解决方法
这是因为权限不够造成的。解决方法为：

打开 CMD（管理员模式）
依次获取每一层的路径权限：
adb shell

su

chmod 777 /data/
chmod 777 /data/data/
chmod 777 /data/data/包名（比如我的是com.likianta.anykey）/
chmod 777 /data/包名/databases/

从而进入databases目录下（以后就不用再获取了，直接一句cd /data/包名/databases/就可以进）。
使用ls命令可以查看该目录下的所有文件：



比如我这里就显示了两个文件，一个是“UserDatabase.db”，另一个是“UserDatabase.db-journal”。
————————————————
版权声明：本文为CSDN博主「Likianta Me」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Likianta/java/article/details/78691069
