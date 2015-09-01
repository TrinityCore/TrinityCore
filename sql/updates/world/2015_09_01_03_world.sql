--
UPDATE `creature` SET `phaseMask`=1 WHERE `phaseMask`=65535;
UPDATE `creature` SET `PhaseId`=169 WHERE `phaseMask`=1;
UPDATE `creature` SET `PhaseId`=170 WHERE `phaseMask`=2;
UPDATE `creature` SET `PhaseId`=171 WHERE `phaseMask`=4;
UPDATE `creature` SET `PhaseId`=172 WHERE `phaseMask`=8;
UPDATE `creature` SET `PhaseId`=173 WHERE `phaseMask`=16;
UPDATE `creature` SET `PhaseId`=174 WHERE `phaseMask`=32;
UPDATE `creature` SET `PhaseId`=175 WHERE `phaseMask`=64;
UPDATE `creature` SET `PhaseId`=176 WHERE `phaseMask`=128;
UPDATE `creature` SET `PhaseId`=177 WHERE `phaseMask`=256;
