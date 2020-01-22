--
delete from `trinity_string` where `entry`=600;
insert into `trinity_string` (entry,content_default,content_loc1,content_loc2,content_loc3,content_loc4,content_loc5,content_loc6,content_loc7,content_loc8) values
(600, "Failed to remove itemID = %i, amount = %i, from %s (No such item exists in target's inventory)", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
