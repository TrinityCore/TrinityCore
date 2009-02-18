-- 
-- NOTE: If you have temporary stored data in table `eventai_localized_texts` make sure to make backup of this before running this update!
-- NOTE: If you have any texts in current eventai_texts and they are not using entries valid for *_texts table, you _will_ get error messages on startup.
-- NOTE: Do not run this update twice, it may create bad data if you choose to do so.
-- 

-- drop obsolete table
DROP TABLE eventai_localized_texts;

-- alter and add fields in table `eventai_texts`
ALTER TABLE eventai_texts CHANGE COLUMN `id` `entry` mediumint(8) NOT NULL;
ALTER TABLE eventai_texts CHANGE COLUMN `text` `content_default` text NOT NULL AFTER `entry`;
ALTER TABLE eventai_texts ADD COLUMN `content_loc1` text AFTER `content_default`;
ALTER TABLE eventai_texts ADD COLUMN `content_loc2` text AFTER `content_loc1`;
ALTER TABLE eventai_texts ADD COLUMN `content_loc3` text AFTER `content_loc2`;
ALTER TABLE eventai_texts ADD COLUMN `content_loc4` text AFTER `content_loc3`;
ALTER TABLE eventai_texts ADD COLUMN `content_loc5` text AFTER `content_loc4`;
ALTER TABLE eventai_texts ADD COLUMN `content_loc6` text AFTER `content_loc5`;
ALTER TABLE eventai_texts ADD COLUMN `content_loc7` text AFTER `content_loc6`;
ALTER TABLE eventai_texts ADD COLUMN `content_loc8` text AFTER `content_loc7`;
ALTER TABLE eventai_texts ADD COLUMN `sound` mediumint(8) unsigned NOT NULL default '0' AFTER `content_loc8`;
ALTER TABLE eventai_texts ADD COLUMN `type` tinyint unsigned NOT NULL default '0' AFTER `sound`;
ALTER TABLE eventai_texts ADD COLUMN `language` tinyint unsigned NOT NULL default '0' AFTER `type`;
ALTER TABLE eventai_texts MODIFY COLUMN `comment` text;

-- get our current action type, and update text type = yell
UPDATE eventai_texts,eventai_scripts SET eventai_texts.type=1 WHERE eventai_scripts.action1_type IN (2,7) AND eventai_scripts.action1_param1=eventai_texts.entry;
UPDATE eventai_texts,eventai_scripts SET eventai_texts.type=1 WHERE eventai_scripts.action2_type IN (2,7) AND eventai_scripts.action2_param1=eventai_texts.entry;
UPDATE eventai_texts,eventai_scripts SET eventai_texts.type=1 WHERE eventai_scripts.action3_type IN (2,7) AND eventai_scripts.action3_param1=eventai_texts.entry;
-- get our current action type, and update text type = textemote
UPDATE eventai_texts,eventai_scripts SET eventai_texts.type=2 WHERE eventai_scripts.action1_type IN (3,8) AND eventai_scripts.action1_param1=eventai_texts.entry;
UPDATE eventai_texts,eventai_scripts SET eventai_texts.type=2 WHERE eventai_scripts.action2_type IN (3,8) AND eventai_scripts.action2_param1=eventai_texts.entry;
UPDATE eventai_texts,eventai_scripts SET eventai_texts.type=2 WHERE eventai_scripts.action3_type IN (3,8) AND eventai_scripts.action3_param1=eventai_texts.entry;

-- update our scripts, for all action type 2, 3, 6, 7 & 8 to become 1
UPDATE eventai_scripts SET action1_type=1 WHERE action1_type IN (2,3,6,7,8);
UPDATE eventai_scripts SET action2_type=1 WHERE action2_type IN (2,3,6,7,8);
UPDATE eventai_scripts SET action3_type=1 WHERE action3_type IN (2,3,6,7,8);

-- was OOC, so at least one could be -1, set this to 0 (dev note: below will be bad, if run twice)
UPDATE eventai_scripts SET action1_param2=0 WHERE action1_type=1 AND action1_param2=-1;
UPDATE eventai_scripts SET action1_param3=0 WHERE action1_type=1 AND action1_param3=-1;
UPDATE eventai_scripts SET action2_param2=0 WHERE action2_type=1 AND action2_param2=-1;
UPDATE eventai_scripts SET action2_param3=0 WHERE action2_type=1 AND action2_param3=-1;
UPDATE eventai_scripts SET action3_param2=0 WHERE action3_type=1 AND action3_param2=-1;
UPDATE eventai_scripts SET action3_param3=0 WHERE action3_type=1 AND action3_param3=-1;

-- expect all to be action type 1 now, continue convert to negative text entry
UPDATE eventai_scripts SET action1_param1=(`action1_param1`) *-1 WHERE action1_type=1 AND action1_param1>0;
UPDATE eventai_scripts SET action2_param1=(`action2_param1`) *-1 WHERE action2_type=1 AND action2_param1>0;
UPDATE eventai_scripts SET action3_param1=(`action3_param1`) *-1 WHERE action3_type=1 AND action3_param1>0;

UPDATE eventai_scripts SET action1_param2=(`action1_param2`) *-1 WHERE action1_type=1 AND action1_param2>0;
UPDATE eventai_scripts SET action2_param2=(`action2_param2`) *-1 WHERE action2_type=1 AND action2_param2>0;
UPDATE eventai_scripts SET action3_param2=(`action3_param2`) *-1 WHERE action3_type=1 AND action3_param2>0;

UPDATE eventai_scripts SET action1_param3=(`action1_param3`) *-1 WHERE action1_type=1 AND action1_param3>0;
UPDATE eventai_scripts SET action2_param3=(`action2_param3`) *-1 WHERE action2_type=1 AND action2_param3>0;
UPDATE eventai_scripts SET action3_param3=(`action3_param3`) *-1 WHERE action3_type=1 AND action3_param3>0;

-- now we have negative numbers in script, must make sure text entries have same entry as script
UPDATE eventai_texts SET entry=(`entry`) *-1 WHERE entry>0;

ALTER TABLE script_texts MODIFY COLUMN `sound` mediumint(8) unsigned NOT NULL default '0';

