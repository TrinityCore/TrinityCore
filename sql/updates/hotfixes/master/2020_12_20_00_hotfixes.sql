-- Hotfixes Remove Data From broadcast_text_locale that causes DBErrors

-- deDE
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' and `id` IN (144568, 142621, 141927, 141776, 141775, 141501);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' and `id` IN (141469, 141468, 141467, 141466, 141465, 141464);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' and `id` IN (141305, 141161, 141160, 141151, 141150, 141148);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' and `id` IN (141146, 141145, 141141, 141128, 141126, 141105);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' and `id` IN (141104, 141103, 141102, 141101, 141099, 141098);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' and `id` IN (141097, 141070, 141069, 140968, 140945, 140944);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' and `id` IN (140942, 140919, 140918, 140917, 140797, 140795);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' and `id` IN (140760, 140736, 140735, 140734, 140733, 140732);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' and `id` IN (140731, 140730, 140712, 140711, 140710, 140709);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' and `id` IN (140708, 140644, 140475, 140474, 140473, 140472);

-- itIT

DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' and `id` IN (144568, 142621, 141927, 141776, 141775, 141501);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' and `id` IN (141469, 141468, 141467, 141466, 141465, 141464);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' and `id` IN (141305, 141161, 141160, 141151, 141150, 141148);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' and `id` IN (141146, 141145, 141141, 141128, 141126, 141105);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' and `id` IN (141104, 141103, 141102, 141101, 141099, 141098);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' and `id` IN (141097, 141070, 141069, 140968, 140945, 140944);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' and `id` IN (140942, 140919, 140918, 140917, 140797, 140795);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' and `id` IN (140760, 140736, 140735, 140734, 140733, 140732);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' and `id` IN (140731, 140730, 140712, 140711, 140710, 140709);
DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' and `id` IN (140708, 140644, 140475, 140474, 140472, 140473);

DELETE FROM `broadcast_text_locale` WHERE `ID` IN (144568, 142621, 141927, 141776, 141775, 141501);