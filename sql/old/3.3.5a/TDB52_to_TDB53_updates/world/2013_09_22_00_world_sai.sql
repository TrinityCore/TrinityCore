UPDATE `smart_scripts` SET `link`=3 WHERE `entryorguid` IN (22401,21182,22402,22403) AND `source_type`=0 AND `id`=2 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22401,21182,22402,22403) AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(22401,3,61,33,22401,7,'Zeth''Gor Quest Credit Marker, They Must Burn, Tower North - On spell hit - Give Quest Credit'),
(21182,3,61,33,21182,7,'Zeth''Gor Quest Credit Marker, They Must Burn, Tower South - On spell hit - Give Quest Credit'), 
(22402,3,61,33,22402,7,'Zeth''Gor Quest Credit Marker, They Must Burn, Tower Forge - On spell hit - Give Quest Credit'),
(22403,3,61,33,22403,7,'Zeth''Gor Quest Credit Marker, They Must Burn, Tower Foothill - On spell hit - Give Quest Credit');
