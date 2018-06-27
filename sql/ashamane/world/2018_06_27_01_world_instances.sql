DELETE FROM `instance_encounters` WHERE (entry BETWEEN 1805 AND 1809) OR (entry BETWEEN 1832 AND 1839);
INSERT INTO `instance_encounters` VALUES
(1805, 0, 94960, 0,     "Hymdall"),
(1806, 0, 95833, 0,     "Hyrja"),
(1807, 0, 99868, 0,     "Fenryr"),
(1808, 0, 95675, 0,     "God-King Skovald"),
(1809, 0, 95676, 1193,  "Odyn"),

(1832, 0, 98542, 0,     "Amalgam of Souls"),
(1833, 0, 98696, 0,     "Ilysanna Ravencrest"),
(1834, 0, 98948, 0,     "Smashspite the Hateful"),
(1835, 0, 99611, 1204,  "Lord Kur'talos Ravencrest"),

(1836, 0, 96512,  0,    "Archidruid Glaidalis"),
(1837, 0, 103344, 0,    "Oakheart"),
(1838, 0, 99200,  0,    "Dresaron"),
(1839, 0, 99192,  1201, "Shade of Xavius");
