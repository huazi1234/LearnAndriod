Android Environment 获取各种路径的方法
[java] view plain copy
 
<pre name="code" class="java">package com.deepoon.beyond.environment;  
  
import android.app.Activity;  
import android.content.Context;  
import android.os.Bundle;  
import android.os.Environment;  
import android.widget.TextView;  
  
import com.deepoon.beyond.R;  
  
public class EnvironmentActivity extends Activity {  
    private Context mContext;  
  
    @Override  
    protected void onCreate(Bundle savedInstanceState) {  
        super.onCreate(savedInstanceState);  
        mContext = this;  
        setContentView(R.layout.activity_environment);  
        TextView textViewDataDirectory = (TextView) findViewById(R.id.textview_data_directory);  
        textViewDataDirectory.setText(Environment.getDataDirectory().getPath());  
  
        TextView textViewRootDirectory = (TextView) findViewById(R.id.textview_root_directory);  
        textViewRootDirectory.setText(Environment.getRootDirectory().getPath());  
  
        TextView textViewExternalStorageState = (TextView) findViewById(R.id.textview_external_storage_state);  
        textViewExternalStorageState.setText(Environment.getExternalStorageState().toString());  
  
        TextView textViewDownloadCacheDirectory = (TextView) findViewById(R.id.textview_download_cache_directory);  
        textViewDownloadCacheDirectory.setText(Environment.getDownloadCacheDirectory().getPath());  
  
        TextView textViewExternalStorageDirectory = (TextView) findViewById(R.id.textview_external_storage_directory);  
        textViewExternalStorageDirectory.setText(Environment.getExternalStorageDirectory().getPath());  
  
        TextView textViewExternalStorageEmulated = (TextView) findViewById(R.id.textview_external_storage_emulated);  
        textViewExternalStorageEmulated.setText("设备的外存是否是用内存模拟的: " + Environment.isExternalStorageEmulated());  
  
        TextView textViewExternalStorageRemovable = (TextView) findViewById(R.id.textview_external_storage_removable);  
        textViewExternalStorageRemovable.setText("设备的外存是否是可以拆卸的: " + Environment.isExternalStorageRemovable());  
  
        TextView textViewDirectoryAlarms = (TextView) findViewById(R.id.textview_directory_alarms);  
        textViewDirectoryAlarms.setText(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_ALARMS).getPath());  
  
        TextView textViewDirectoryDCIM = (TextView) findViewById(R.id.textview_directory_dcim);  
        textViewDirectoryDCIM.setText(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DCIM).getPath());  
  
        TextView textViewDirectoryDocuments = (TextView) findViewById(R.id.textview_directory_documents);  
        textViewDirectoryDocuments.setText(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOCUMENTS).getPath());  
  
        TextView textViewDirectoryDownloads = (TextView) findViewById(R.id.textview_directory_downloads);  
        textViewDirectoryDownloads.setText(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS).getPath());  
  
        TextView textViewDirectoryMovies = (TextView) findViewById(R.id.textview_directory_movies);  
        textViewDirectoryMovies.setText(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_MOVIES).getPath());  
  
        TextView textViewDirectoryMusic = (TextView) findViewById(R.id.textview_directory_music);  
        textViewDirectoryMusic.setText(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_MUSIC).getPath());  
  
        TextView textViewDirectoryNotifications = (TextView) findViewById(R.id.textview_directory_notifications);  
        textViewDirectoryNotifications.setText(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_NOTIFICATIONS).getPath());  
  
        TextView textViewDirectoryPictures = (TextView) findViewById(R.id.textview_directory_pictures);  
        textViewDirectoryPictures.setText(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES).getPath());  
  
        TextView textViewDirectoryPodcasts = (TextView) findViewById(R.id.textview_directory_podcasts);  
        textViewDirectoryPodcasts.setText(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PODCASTS).getPath());  
  
        TextView textViewDirectoryRingtones = (TextView) findViewById(R.id.textview_directory_ringtones);  
        textViewDirectoryRingtones.setText(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_RINGTONES).getPath());  
  
        TextView textViewFilesDir = (TextView) findViewById(R.id.textview_files_dir);  
        textViewFilesDir.setText(mContext.getFilesDir().getPath());  
  
        TextView textViewCacheDir = (TextView) findViewById(R.id.textview_cache_dir);  
        textViewCacheDir.setText(mContext.getCacheDir().getPath());  
  
        TextView textViewExternalFilesDir = (TextView) findViewById(R.id.textview_external_files_dir);  
        textViewExternalFilesDir.setText(mContext.getExternalFilesDir(Environment.DIRECTORY_MOVIES).getPath());  
  
        TextView textViewExternalCacheDir = (TextView) findViewById(R.id.textview_external_cache_dir);  
        textViewExternalCacheDir.setText(mContext.getExternalCacheDir().getPath());  
  
    }  
}  
[java] view plain copy
 
</pre><pre name="code" class="html"><?xml version="1.0" encoding="utf-8"?>  
<LinearLayout  
    xmlns:android="http://schemas.android.com/apk/res/android"  
    android:layout_width="match_parent"  
    android:layout_height="match_parent"  
    >  
  
    <ScrollView  
        android:layout_width="match_parent"  
        android:layout_height="match_parent">  
  
        <LinearLayout  
            android:layout_width="match_parent"  
            android:layout_height="match_parent"  
            android:gravity="center"  
            android:orientation="vertical">  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="------------------Environment API-----------------------"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_root_directory"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="Environment.getRootDirectory()"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_data_directory"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="Environment.getDataDirectory()"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_external_storage_state"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="Environment.getExternalStorageState()"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_download_cache_directory"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="Environment.getDownloadCacheDirectory()"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_external_storage_directory"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="Environment.getExternalStorageDirectory()"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_external_storage_emulated"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="Environment.isExternalStorageEmulated()"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_external_storage_removable"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="Environment.isExternalStorageRemovable()"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:text="注意：传入的类型参数不能是null，返回的目录路径有可能不存在，所以必须在使用之前确认一下，比如使用File.mkdirs创建该路径"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_directory_alarms"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="系统提醒铃声: Environment.DIRECTORY_ALARMS"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_directory_dcim"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="相机拍摄照片和视频: Environment.DIRECTORY_DCIM"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_directory_documents"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="文档: Environment.DIRECTORY_DOCUMENTS"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_directory_downloads"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="下载: Environment.DIRECTORY_DOWNLOADS"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_directory_movies"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="电影: Environment.DIRECTORY_MOVIES"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_directory_music"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="音乐: Environment.DIRECTORY_MUSIC"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_directory_notifications"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="系统通知铃声: Environment.DIRECTORY_NOTIFICATIONS"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_directory_pictures"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="图片: Environment.DIRECTORY_PICTURES"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_directory_podcasts"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="系统广播: Environment.DIRECTORY_PODCASTS"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_directory_ringtones"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="系统铃声: Environment.DIRECTORY_RINGTONES"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="--------------------Context API------------------------"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_files_dir"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="应用的在系统内部Files: Context.getFilesDir()"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_cache_dir"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="应用的在系统内部Cache: Context.getCacheDir()"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_external_files_dir"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="应用的在SDCard Files: Context.getExternalFilesDir()"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:id="@+id/textview_external_cache_dir"  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:layout_marginTop="10dp"  
                android:textSize="14sp"/>  
  
            <TextView  
                android:layout_width="wrap_content"  
                android:layout_height="wrap_content"  
                android:text="应用的在SDCard Files: Context.getExternalCacheDir()"  
                android:textSize="14sp"/>  
        </LinearLayout>  
    </ScrollView>  
</LinearLayout>  
