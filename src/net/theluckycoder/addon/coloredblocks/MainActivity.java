package net.theluckycoder.addon.coloredblocks;

import android.Manifest;
import android.app.Activity;
import android.os.Bundle;
import android.os.Build;
import android.content.Intent;
import android.net.Uri;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;
import android.content.pm.PackageManager;

public class MainActivity extends Activity {
	
    final private int REQUEST_CODE_ASK_PERMISSIONS = 123;
	
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
		
		if (Build.VERSION.SDK_INT >= 23)
			checkForPermission();
    }

	public void downloadLauncher(View view) {
		startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://play.google.com/store/apps/details?id=net.zhuoweizhang.mcpelauncher")));
	}

    private void checkForPermission() {
        int hasWriteContactsPermission = checkSelfPermission(Manifest.permission.WRITE_CONTACTS);
        if (hasWriteContactsPermission != PackageManager.PERMISSION_GRANTED) {
            requestPermissions(new String[] {"net.zhuoweizhang.mcpelauncher.ADDON"}, REQUEST_CODE_ASK_PERMISSIONS);
            return;
        }
    }
}

