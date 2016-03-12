--
UPDATE `creature_text` SET `text`='Sands consume you!', `BroadcastTextId`=6221, `sound`=5872 WHERE `entry`=7271 AND `GroupId`=1;
UPDATE `creature_text` SET `sound`=5872 WHERE `entry`=7271 AND `GroupId`=2 AND `id`=2;
UPDATE `creature_text` SET `sound`=5873 WHERE `entry`=7271 AND `GroupId`=2 AND `id`=3;
-- Fix faction for some Ethereum prisoners
UPDATE `creature_template` SET `faction`=1800 WHERE `entry`IN (20783, 20784, 20785, 20786, 20788, 20789, 20790); 
