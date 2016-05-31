UPDATE `creature` SET `PhaseId`=170 WHERE `PhaseId`=2;
UPDATE `creature` SET `PhaseId`=171 WHERE `PhaseId`=4;
UPDATE `creature` SET `PhaseId`=173 WHERE `PhaseId`=16;
UPDATE `creature` SET `PhaseId`=176 WHERE `PhaseId`=128;

UPDATE `creature` SET `PhaseId`=169 WHERE `PhaseId`=65535;
UPDATE `creature` SET `PhaseId`=0, `PhaseGroup`=371 WHERE `PhaseId`=3;
UPDATE `creature` SET `PhaseGroup`=0 WHERE `PhaseGroup`=1;

UPDATE `gameobject` SET `PhaseId`=169 WHERE `PhaseId`=1;
UPDATE `gameobject` SET `PhaseId`=170 WHERE `PhaseId`=2;
UPDATE `gameobject` SET `PhaseId`=174 WHERE `PhaseId`=32;
UPDATE `gameobject` SET `PhaseId`=175 WHERE `PhaseId`=64;

UPDATE `gameobject` SET `PhaseId`=169 WHERE `PhaseId`=65535;
UPDATE `gameobject` SET `PhaseGroup`=0 WHERE `PhaseGroup`=1;
