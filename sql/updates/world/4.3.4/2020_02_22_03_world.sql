DELETE FROM `gameobject_template` WHERE `entry`= 17155;
DELETE FROM `gameobject_template_addon` WHERE `entry`= 17155;
DELETE FROM `gameobject_loot_template` WHERE `entry`= 2882;
DELETE FROM `quest_mail_sender` WHERE `QuestId` IN (22817, 22818);
DELETE FROM `event_scripts` WHERE `id`= 619;
