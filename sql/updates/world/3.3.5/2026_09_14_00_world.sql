UPDATE `trinity_string` SET
  `content_default`=REPLACE(`content_default`,'16','%u'),
  `content_loc1`=REPLACE(`content_loc1`,'16','%u'),
  `content_loc2`=REPLACE(`content_loc2`,'16','%u'),
  `content_loc3`=REPLACE(`content_loc3`,'16','%u'),
  `content_loc4`=REPLACE(`content_loc4`,'16','%u'),
  `content_loc5`=REPLACE(`content_loc5`,'16','%u'),
  `content_loc6`=REPLACE(`content_loc6`,'16','%u'),
  `content_loc7`=REPLACE(`content_loc7`,'16','%u'),
  `content_loc8`=REPLACE(`content_loc8`,'16','%u')
  WHERE `entry`=1005;
