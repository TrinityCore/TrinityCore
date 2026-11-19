-- 
UPDATE `creature_formations` SET `groupAI`=7 WHERE `groupAI`=2; -- members attack and members follow the leader
UPDATE `creature_formations` SET `groupAI`=4 WHERE `groupAI`=0; -- members follow the leader
UPDATE `creature_formations` SET `groupAI`=5 WHERE `groupAI`=1; -- The members aggroes if the leader aggroes and  members follow the leader
