-- Quest Discrediting the Deserters (11133)
-- Script Texts
DELETE FROM `script_texts` WHERE `entry` BETWEEN (-1603510) AND (-1603502);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`)
VALUES
(4979,-1603502,'Hey, thanks.','NULL','NULL','NULL','NULL','NULL','NULL','NULL','NULL',0,0,0,0, 'Theramore Guard - SAY_QUEST1'),
(4979,-1603503,'...receive 50 percent off deserter undergarments? What is this garbage?','NULL','NULL','NULL','NULL','NULL','NULL','NULL','NULL',0,0,0,0,'Theramore Guard - SAY_QUEST2'),
(4979,-1603504,'...to establish a fund for the purchase of hair gel? I like my hair the way it is, thanks!','NULL','NULL','NULL','NULL','NULL','NULL','NULL','NULL',0,0,0,0,'Theramore Guard - SAY_QUEST3'),
(4979,-1603505,'...the deserters seek a Theramore where citizens will be free to juggle at all hours of the day? What is this nonsense?','NULL','NULL','NULL','NULL','NULL','NULL','NULL','NULL',0,0,0,0,'Theramore Guard - SAY_QUEST4'),
(4979,-1603506,'...to establish the chicken as the official symbol of Theramore?! These guys are nuts!','NULL','NULL','NULL','NULL','NULL','NULL','NULL','NULL',0,0,0,0,'Theramore Guard - SAY_QUEST5'),
(4979,-1603507,'...as a deserter, you\'ll enjoy activities like tethered swimming and dog grooming? How ridiculous!','NULL','NULL','NULL','NULL','NULL','NULL','NULL','NULL',0,0,0,0,'Theramore Guard - SAY_QUEST6'),
(4979,-1603508,'This... this is a joke, right?','NULL','NULL','NULL','NULL','NULL','NULL','NULL','NULL',0,0,0,0,'Theramore Guard - SAY_QUEST7'),
(4979,-1603509,'I\'d never join anything like this. Better keep this, though. It\'ll come in handy in the privy...','NULL','NULL','NULL','NULL','NULL','NULL','NULL','NULL',0,0,0,0,'Theramore Guard - SAY_QUEST8'),
(4979,-1603510,'What a bunch of lunatics! You actually believe this stuff?','NULL','NULL','NULL','NULL','NULL','NULL','NULL','NULL',0,0,0,0,'Theramore Guard - SAY_QUEST9');
