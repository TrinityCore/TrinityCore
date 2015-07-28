UPDATE `smart_scripts` SET `link`=2,`action_type`=33,`action_param1`=29692,`target_type`=7,`comment`='Hut Fire - On Spell Hit - Give Quest Credit' WHERE `entryorguid`=29692 AND `source_type`=0 AND `id`=1 AND `link`=0; 
DELETE FROM `smart_scripts` WHERE `entryorguid`=29692 AND `id`=2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `action_type`, `target_type`, `comment`) VALUES
(29692,2,61,41,1, 'Hut Fire - Link With Event 1 - Despawn'); 
