-- Wrong start/end NPCs for Caverns of Time Chain:
-- Andormu(man) should be Andormu(child)
UPDATE `creature_involvedrelation` SET `id`=20130 WHERE `quest`IN(10285,10298); 
UPDATE `creature_questrelation` SET `id`=20130 WHERE `quest`=10296;
