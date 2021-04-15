DELETE FROM `disables` WHERE `entry` IN (1242, 1803, 1804, 1805, 1806, 1807, 1808, 1809, 1810, 1825, 1811, 1812, 1813, 1814, 1815, 1816, 1817, 1818, 1819, 1826, 3386, 3387, 3388, 3389) AND `sourceType` = 4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (1242, 1803, 1804, 1805, 1806, 1807, 1808, 1809, 1810, 1825, 1811, 1812, 1813, 1814, 1815, 1816, 1817, 1818, 1819, 1826, 3386, 3387, 3388, 3389);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(1242, 11, 0, 0, 'achievement_bg_av_perfection'),
(1803, 11, 0, 0, 'achievement_bg_av_perfection'),
(1804, 11, 0, 0, 'achievement_bg_av_perfection'),
(1805, 11, 0, 0, 'achievement_bg_av_perfection'),
(1806, 11, 0, 0, 'achievement_bg_av_perfection'),
(1807, 11, 0, 0, 'achievement_bg_av_perfection'),
(1808, 11, 0, 0, 'achievement_bg_av_perfection'),
(1809, 11, 0, 0, 'achievement_bg_av_perfection'),
(1810, 11, 0, 0, 'achievement_bg_av_perfection'),
(1825, 11, 0, 0, 'achievement_bg_av_perfection'),
(1811, 11, 0, 0, 'achievement_bg_av_perfection'),
(1812, 11, 0, 0, 'achievement_bg_av_perfection'),
(1813, 11, 0, 0, 'achievement_bg_av_perfection'),
(1814, 11, 0, 0, 'achievement_bg_av_perfection'),
(1815, 11, 0, 0, 'achievement_bg_av_perfection'),
(1816, 11, 0, 0, 'achievement_bg_av_perfection'),
(1817, 11, 0, 0, 'achievement_bg_av_perfection'),
(1818, 11, 0, 0, 'achievement_bg_av_perfection'),
(1819, 11, 0, 0, 'achievement_bg_av_perfection'),
(1826, 11, 0, 0, 'achievement_bg_av_perfection'),
(3386, 11, 0, 0, 'achievement_everything_counts'),
(3387, 11, 0, 0, 'achievement_everything_counts'),
(3388, 11, 0, 0, 'achievement_everything_counts'),
(3389, 11, 0, 0, 'achievement_everything_counts');