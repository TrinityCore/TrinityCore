
UPDATE `phase_name` SET `Name`='Cosmetic - See Cyrus Crestfall in Harbormasters Office' WHERE `ID`=10827;
UPDATE `phase_name` SET `Name`='Cosmetic - See Taelia in Harbormasters Office' WHERE `ID`=9001;

UPDATE `phase_area` SET `Comment`='Cosmetic - See Cyrus Crestfall in Harbormasters Office' WHERE `PhaseId`=10827;
UPDATE `phase_area` SET `Comment`='Cosmetic - See Taelia in Harbormasters Office' WHERE `PhaseId`=9001;

UPDATE `creature` SET `PhaseId`=9001 WHERE `guid`=8000038; -- Taelia
UPDATE `creature` SET `PhaseId`=10827 WHERE `guid`=8000039; -- Cyrus Crestfall
