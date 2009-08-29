-- spell 30298 tries to start event script 10675 but it doesn't exist. create it & make it spawn Geezle
delete from event_scripts where id = 10675;
insert into `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `x`, `y`, `z`, `o`) values 
(10675, 0, 10, 17318, 90000, '-5139.79','-11248.27','5.23', '6.27609');

-- geezle should not spawn by default
update creature set spawnMask=0 where guid = 85587;

-- add missing sentence to Geezle's text & Overgrind's name to flag pickup emote
# delete from `script_texts` where `entry` in (-1000266,-1000259);
# insert into `script_texts` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) values
('-1000266','%s picks up the naga flag.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','2','0','0','geezle - EMOTE_SPARK'),
('-1000259','What\'s the big idea, Spark? Why\'d you call for this meeting?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','0','0','0','geezle - GEEZLE_SAY_1');

