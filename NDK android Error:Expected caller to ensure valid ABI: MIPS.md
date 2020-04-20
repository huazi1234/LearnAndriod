

NDK android Error:Expected caller to ensure valid ABI: MIPS
android studio 安装NDK之后，报错 Error:Expected caller to ensure valid ABI: MIPS

 


环境：

android studio 2.3

gradle-3.3-all

dependencies {
classpath 'com.android.tools.build:gradle:2.3.3'
}

 

安装NDK的方式：直接在SDK tools底下安装的(LLDB、CMAKE、NDK)

先出现的问题是：Error:No toolchains found in the NDK toolchains folder for ABI with prefix: mips64el-linux-android

解决方法是：按照网上的方法，下载NDK r11b的版本，将里面的mips64el文件夹复制到自己的ndk-bundle/toolchains下。具体查阅百度。我上传了这个文件夹，不用去下载整个NDK了，链接如下：

链接：https://pan.baidu.com/s/1yTJw86BtAz24xGCdvCMUvg
提取码：5ebw


但是这种方法好像不太好，因为听说是因为NDK不支持mips64el这玩意了，并不是少了这个文件夹。但是其他方法我都试了，没用，这样能用就行了。。。

 

解决完这个问题，重新sync，报错：

Error:Expected caller to ensure valid ABI: MIPS

解决方法(参考): 在app/build.gradle里的 defaultConfig里 添加

1
2
3
ndk {
    abiFilters 'armeabi-v7a','arm64-v8a','x86','x86_64'
}
　　

整个配置如下（添加的部分在16~18行）：

android {
    compileSdkVersion 25
    buildToolsVersion "25.0.3"
    defaultConfig {
        applicationId "com.yongyang.myapplicationndk03"
        minSdkVersion 15
        targetSdkVersion 25
        versionCode 1
        versionName "1.0"
        testInstrumentationRunner "android.support.test.runner.AndroidJUnitRunner"
        externalNativeBuild {
            cmake {
                cppFlags ""
            }
        }
        ndk {
            abiFilters 'armeabi-v7a','arm64-v8a','x86','x86_64'
        }
    }
    buildTypes {
        release {
            minifyEnabled false
            proguardFiles getDefaultProguardFile('proguard-android.txt'), 'proguard-rules.pro'
        }
    }
    externalNativeBuild {
        cmake {
            path "CMakeLists.txt"
        }
    }
}
　　

重新sync就好了。
