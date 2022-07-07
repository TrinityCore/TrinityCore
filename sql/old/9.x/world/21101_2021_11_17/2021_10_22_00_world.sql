-- 
DELETE FROM `instance_template` WHERE `map` IN(1771, 1841, 1862, 1864, 1877);
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES
(1771, 0, '', 1), -- Tol Dagor
(1841, 0, '', 1), -- The Underrot
(1862, 0, '', 1), -- Waycrest Manor
(1864, 0, '', 1), -- Shrine of the Storm
(1877, 0, '', 1); -- Temple of Sethraliss
