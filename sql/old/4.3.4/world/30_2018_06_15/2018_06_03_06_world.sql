-- 
UPDATE `gameobject` SET `PhaseId`=169, `phaseMask`=1 WHERE `guid`=200623;
UPDATE `gameobject` SET `PhaseId`=169 WHERE `phaseMask`=1 AND `PhaseId`=0 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=170 WHERE `phaseMask`=2 AND `PhaseId`=0 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=169 WHERE `phaseMask`=1 AND `PhaseId`=0 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=171 WHERE `phaseMask`=4 AND `PhaseId`=0 AND `PhaseGroup`=0;
