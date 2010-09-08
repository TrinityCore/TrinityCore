DELETE FROM `outdoorpvp_template` WHERE `TypeId` IN (1,2,3,4,5,6);
INSERT INTO `outdoorpvp_template` (`TypeId`, `ScriptName`, `Comment`) VALUES
(1, 'outdoorpvp_hp', 'Hellfire Peninsula'),
(2, 'outdoorpvp_na', 'Nagrand'),
(3, 'outdoorpvp_tf', 'Terokkar Forest'),
(4, 'outdoorpvp_zm', 'Zangarmarsh'),
(5, 'outdoorpvp_si', 'Silithus'),
(6, 'outdoorpvp_ep', 'Eastern Plaguelands');
