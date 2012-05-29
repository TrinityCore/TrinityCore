-- Eye of Achrus texts
DELETE FROM `creature_text` WHERE `entry` IN (28511);

INSERT  INTO `creature_text` VALUES 
(28511,1,0,'The Eye of Acherus launches towards its destination.',42,0,100,0,0,0,'Eye of Achrus - SAY_EYE_LAUNCHED'),
(28511,2,0,'The Eye of Acherus is in your control.',42,0,100,0,0,0,'Eye of Achrus - SAY_EYE_UNDER_CONTROL');