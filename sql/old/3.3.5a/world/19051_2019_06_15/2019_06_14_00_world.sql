-- 
UPDATE `quest_template_addon` SET `SpecialFlags`=1 WHERE `ID` IN (8544,  8559,  8560,  8561,  8562,  8592,  8593,  8594,  8596,  8602,  8603,  8621,  8622,  8623,  8624,  8625,  8626,  8627,  8628,  8629,  8630,  8631,  8632,  8633,  8634,  8637,  8638,  8639,  8640,  8641,  8655,  8656,  8657,  8658,  8659,  8660,  8661,  8662,  8663,  8664,  8665,  8666,  8667,  8668,  8669);
DELETE FROM `quest_template_addon`    WHERE `ID` IN (8789,  8790);
INSERT INTO `quest_template_addon` (`ID`, `SpecialFlags`) VALUES
(8789, 1),
(8790, 1);
