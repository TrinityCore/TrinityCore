UPDATE `trinity_string` SET
  `content_default`=REPLACE(`content_default`,'%i','%.2f'),
  `content_loc1`=REPLACE(`content_loc1`,'%i','%.2f'),
  `content_loc2`=REPLACE(`content_loc2`,'%i','%.2f'),
  `content_loc3`=REPLACE(`content_loc3`,'%i','%.2f'),
  `content_loc4`=REPLACE(`content_loc4`,'%i','%.2f'),
  `content_loc5`=REPLACE(`content_loc5`,'%i','%.2f'),
  `content_loc6`=REPLACE(`content_loc6`,'%i','%.2f'),
  `content_loc7`=REPLACE(`content_loc7`,'%i','%.2f'),
  `content_loc8`=REPLACE(`content_loc8`,'%i','%.2f')
  WHERE `entry`=470;
