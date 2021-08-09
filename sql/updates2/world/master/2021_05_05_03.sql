DELETE FROM `areatrigger_template` WHERE `Id`=26146;
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(26146, 1, 0, 4, 10, 10, 0, 0, 0, 0, 38134);


UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=8382;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=10560;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12676;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=8382;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12676;
UPDATE `areatrigger_template` SET `Flags`=2 WHERE `Id`=9228;

DELETE FROM `conversation_line_template` WHERE `Id` IN (8390, 8140, 5259, 2357, 7924, 7923, 8011, 8010, 8009, 8141, 5308, 3804, 3813, 7966, 3805, 7934, 2358, 7941, 7940, 8065, 8064, 8066, 8004, 8003, 8008, 8002, 8001, 3826, 3828, 7967, 5309, 7932, 8391, 8143, 5387, 7949, 7948, 7947, 7951, 7950, 7154, 1967, 7872, 7152, 7153, 7918, 7151, 7150, 7149, 7148, 8389, 2552, 2551, 2548, 2549, 2550, 3748, 3822, 3821, 3747, 7961, 7960, 7959, 7958, 3763, 3762, 3761, 3746, 8384, 8029, 8028, 8027, 7946, 7945, 7944, 7943, 7942, 7933, 8068, 8063, 8062, 8061, 7956, 7955, 7954, 7953, 7952, 2352, 2351, 7965, 7964, 7963, 7962, 2376, 2375, 2374, 8014, 8021, 8012, 8013, 7930, 7929, 7937, 7936, 7935, 8031, 8030, 2354, 2353, 8036, 8035, 8034, 8033, 8032, 2356, 7957);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(8390, 0, 0, 0, 0, 38134),
(8140, 6150, 0, 0, 0, 38134),
(5259, 0, 0, 0, 0, 38134),
(2357, 0, 0, 0, 0, 38134),
(7924, 11085, 0, 1, 0, 38134),
(7923, 0, 0, 0, 0, 38134),
(8011, 10299, 0, 0, 0, 38134),
(8010, 3316, 0, 1, 0, 38134),
(8009, 0, 0, 0, 0, 38134),
(8141, 4000, 0, 0, 0, 38134),
(5308, 0, 0, 0, 0, 38134),
(3804, 12128, 0, 3, 0, 38134),
(3813, 6458, 0, 2, 0, 38134),
(7966, 1990, 0, 1, 0, 38134),
(3805, 0, 0, 0, 0, 38134),
(7934, 0, 571, 0, 0, 38134),
(2358, 0, 254, 0, 0, 38134),
(7941, 4153, 0, 1, 0, 38134),
(7940, 0, 0, 0, 0, 38134),
(8065, 24904, 0, 1, 0, 38134),
(8064, 22713, 0, 0, 0, 38134),
(8066, 0, 0, 0, 0, 38134),
(8004, 3214, 0, 1, 0, 38134),
(8003, 0, 0, 0, 0, 38134),
(8008, 9055, 0, 2, 0, 38134),
(8002, 3186, 0, 1, 0, 38134),
(8001, 0, 0, 0, 0, 38134),
(3826, 4116, 0, 2, 0, 38134),
(3828, 2295, 0, 1, 0, 38134),
(7967, 0, 0, 0, 0, 38134),
(5309, 0, 0, 0, 0, 38134),
(7932, 0, 0, 0, 0, 38134),
(8391, 0, 0, 0, 0, 38134),
(8143, 0, 0, 0, 0, 38134),
(5387, 0, 0, 0, 0, 38134),
(7949, 7450, 0, 0, 0, 38134),
(7948, 3369, 0, 1, 0, 38134),
(7947, 0, 0, 0, 0, 38134),
(7951, 2313, 0, 1, 0, 38134),
(7950, 0, 0, 0, 0, 38134),
(7154, 45300, 0, 1, 0, 38134),
(1967, 45300, 0, 6, 1, 38134),
(7872, 39950, 0, 5, 0, 38134),
(7152, 34800, 0, 0, 0, 38134),
(7153, 26600, 0, 4, 0, 38134),
(7918, 21000, 0, 3, 0, 38134),
(7151, 14950, 0, 2, 0, 38134),
(7150, 8900, 0, 0, 0, 38134),
(7149, 4250, 0, 1, 0, 38134),
(7148, 0, 0, 0, 0, 38134),
(8389, 0, 0, 0, 0, 38134),
(2552, 15258, 0, 0, 0, 38134),
(2551, 10025, 0, 3, 0, 38134),
(2548, 6872, 0, 2, 0, 38134),
(2549, 4596, 0, 1, 0, 38134),
(2550, 0, 0, 0, 0, 38134),
(3748, 22284, 0, 0, 0, 38134),
(3822, 6194, 0, 2, 0, 38134),
(3821, 3911, 0, 1, 0, 38134),
(3747, 0, 0, 0, 0, 38134),
(7961, 24519, 0, 0, 0, 38134),
(7960, 14689, 0, 2, 0, 38134),
(7959, 7100, 0, 1, 0, 38134),
(7958, 0, 0, 0, 0, 38134),
(3763, 15612, 0, 3, 0, 38134),
(3762, 11596, 0, 2, 0, 38134),
(3761, 5708, 0, 1, 0, 38134),
(3746, 0, 0, 0, 0, 38134),
(8384, 0, 0, 0, 0, 38134),
(8029, 9024, 0, 2, 0, 38134),
(8028, 4210, 0, 1, 0, 38134),
(8027, 0, 0, 0, 0, 38134),
(7946, 20022, 0, 2, 0, 38134),
(7945, 15692, 0, 1, 0, 38134),
(7944, 11629, 0, 2, 0, 38134),
(7943, 7205, 0, 1, 0, 38134),
(7942, 0, 0, 0, 0, 38134),
(7933, 0, 572, 0, 0, 38134),
(8068, 14078, 0, 1, 0, 38134),
(8063, 9744, 0, 0, 0, 38134),
(8062, 2702, 0, 1, 0, 38134),
(8061, 0, 0, 0, 0, 38134),
(7956, 16397, 0, 0, 0, 38134),
(7955, 10047, 0, 3, 0, 38134),
(7954, 6405, 0, 2, 0, 38134),
(7953, 3290, 0, 1, 0, 38134),
(7952, 0, 0, 0, 0, 38134),
(2352, 7396, 0, 1, 0, 38134),
(2351, 0, 0, 0, 0, 38134),
(7965, 17787, 0, 3, 0, 38134),
(7964, 15158, 0, 2, 0, 38134),
(7963, 7474, 0, 1, 0, 38134),
(7962, 0, 0, 0, 0, 38134),
(2376, 10240, 0, 0, 0, 38134),
(2375, 6561, 0, 1, 0, 38134),
(2374, 0, 0, 0, 0, 38134),
(8014, 9853, 0, 1, 0, 38134),
(8021, 7121, 0, 0, 0, 38134),
(8012, 3459, 0, 1, 0, 38134),
(8013, 0, 0, 0, 0, 38134),
(7930, 4006, 0, 1, 0, 38134),
(7929, 0, 0, 0, 0, 38134),
(7937, 6846, 0, 2, 0, 38134),
(7936, 4183, 0, 1, 0, 38134),
(7935, 0, 0, 0, 0, 38134),
(8031, 4154, 0, 1, 0, 38134),
(8030, 0, 0, 0, 0, 38134),
(2354, 1799, 0, 1, 0, 38134),
(2353, 0, 0, 0, 0, 38134),
(8036, 3455, 0, 1, 0, 38134),
(8035, 0, 0, 0, 0, 38134),
(8034, 12511, 0, 2, 0, 38134),
(8033, 8401, 0, 1, 0, 38134),
(8032, 0, 0, 0, 0, 38134),
(2356, 0, 254, 0, 0, 38134),
(7957, 0, 0, 0, 0, 38134);


UPDATE `conversation_template` SET `FirstLineID`=8389, `LastLineEndTime`=3050 WHERE `Id`=2329;
UPDATE `conversation_template` SET `FirstLineID`=8389, `LastLineEndTime`=3050 WHERE `Id`=2329;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (245866 /*Troll Drum*/, 245881 /*Troll Banner*/, 245875 /*Mat*/, 245864 /*Troll Banner*/, 245863 /*Torch*/, 245880 /*Incense*/, 258064 /*Funeral Pyre*/, 245865 /*Horde Banner*/, 245878 /*Funeral Pyre*/, 246039 /*Protective Barrier*/, 245730 /*Reinforced Gate*/, 242549 /*WMO Bridge*/, 254234 /*WMO Bridge*/, 251426 /*Fel Fire*/, 255203 /*Horde Battleship*/, 251604 /*Alliance Battleship*/, 254275 /*Legion Portal Large*/, 254017 /*Legion Portal*/, 254016 /*Legion Portal*/, 254018 /*Legion Portal*/, 240211 /*Legion Gateway*/, 254252 /*Legion Portal*/, 254251 /*Legion Portal*/, 254250 /*Legion Portal*/, 254015 /*Legion Portal*/, 240214 /*Siege Cannon*/, 257854 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257853 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257852 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257851 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257850 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257849 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257582 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257598 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257597 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257594 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257593 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257610 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257607 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257606 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257603 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257600 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257616 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257580 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257579 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257578 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257599 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257596 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257595 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257592 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257591 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257590 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257588 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257612 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257611 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257609 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257608 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257605 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257604 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257602 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257601 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257583 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257589 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257587 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257586 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257585 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257584 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257615 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257614 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257613 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257618 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257617 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257581 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 259137 /*The End Is Coming!*/, 257705 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257712 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257692 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257747 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257710 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257708 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257707 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257706 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257703 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257702 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257701 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257698 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257696 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257695 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257694 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257693 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257691 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257746 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257709 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257704 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257700 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257699 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257697 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257781 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257780 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257779 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257778 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257777 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257776 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257743 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257742 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257741 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257740 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257739 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257738 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257737 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257736 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257735 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257734 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257733 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257732 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257731 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257730 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257729 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257728 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257759 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257758 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257757 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257756 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257755 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257754 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257753 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257752 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257751 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257750 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257749 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257748 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257745 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257744 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257711 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257727 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257726 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257725 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257724 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257723 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257722 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257721 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257720 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257719 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257718 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257717 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257716 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257715 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257714 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257713 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257679 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257678 /*Noodle Cart*/, 257677 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257676 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257675 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257674 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257673 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257672 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257671 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257670 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257669 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257668 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257667 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257666 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257665 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257664 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257690 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257689 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257687 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257685 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257684 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257683 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257682 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257681 /*Bubbling Pot*/, 257647 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257646 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257645 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257644 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257643 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257642 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257641 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257640 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257639 /*Anvil*/, 257638 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257637 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257636 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257635 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257634 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257633 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257632 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257663 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257662 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257661 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257660 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257659 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257658 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257657 /*Forge*/, 257656 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 259146 /*Goblin Machine*/, 257655 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257654 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257653 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257652 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257651 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257650 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257649 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257648 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257836 /*Horde Battleship*/, 257835 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257834 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257833 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257832 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257631 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257831 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257630 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257830 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257629 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257829 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257628 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257828 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257627 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257827 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257626 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257826 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257825 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257824 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257623 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257622 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257621 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257620 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257619 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257807 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257806 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257805 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257804 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257803 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257802 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257801 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257800 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257799 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257798 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257797 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257796 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257795 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257794 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257793 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257792 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257823 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257822 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257821 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257820 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257819 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257818 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257817 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257816 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257815 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257814 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257813 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257812 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257811 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257810 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257809 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257808 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 259138 /*Goblin Forge*/, 258975 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 258974 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 254942 /*Horde Battleship*/, 257775 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 259121 /*Gregg's Rocks*/, 257774 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257773 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257772 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257771 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257770 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257769 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257768 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257767 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257766 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257765 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257764 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257763 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257762 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257761 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257760 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257791 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257790 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257789 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 259120 /*Gregg's Cart*/, 257788 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257787 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257786 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257785 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257784 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257783 /*7.0 Pre-Launch - Orgrimmar - Template Object*/, 257782 /*7.0 Pre-Launch - Orgrimmar - Template Object*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(245866, 0, 8192, 0, 0), -- Troll Drum
(245881, 0, 8192, 0, 0), -- Troll Banner
(245875, 0, 8192, 0, 0), -- Mat
(245864, 0, 8192, 0, 0), -- Troll Banner
(245863, 0, 8192, 0, 0), -- Torch
(245880, 0, 8192, 0, 0), -- Incense
(258064, 0, 1048608, 0, 0), -- Funeral Pyre
(245865, 0, 8192, 0, 0), -- Horde Banner
(245878, 0, 8192, 0, 0), -- Funeral Pyre
(246039, 0, 34, 0, 0), -- Protective Barrier
(245730, 0, 32, 0, 0), -- Reinforced Gate
(242549, 0, 1048608, 0, 0), -- WMO Bridge
(254234, 0, 1048608, 0, 0), -- WMO Bridge
(251426, 0, 8192, 0, 0), -- Fel Fire
(255203, 0, 1048608, 0, 0), -- Horde Battleship
(251604, 0, 1048608, 0, 0), -- Alliance Battleship
(254275, 1375, 32, 0, 0), -- Legion Portal Large
(254017, 1375, 32, 0, 0), -- Legion Portal
(254016, 1375, 32, 0, 0), -- Legion Portal
(254018, 1375, 32, 0, 0), -- Legion Portal
(240211, 0, 1048608, 0, 0), -- Legion Gateway
(254252, 1375, 32, 0, 0), -- Legion Portal
(254251, 1375, 32, 0, 0), -- Legion Portal
(254250, 1375, 32, 0, 0), -- Legion Portal
(254015, 1375, 32, 0, 0), -- Legion Portal
(240214, 1375, 32, 0, 0), -- Siege Cannon
(257854, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257853, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257852, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257851, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257850, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257849, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257582, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257598, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257597, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257594, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257593, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257610, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257607, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257606, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257603, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257600, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257616, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257580, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257579, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257578, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257599, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257596, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257595, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257592, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257591, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257590, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257588, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257612, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257611, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257609, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257608, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257605, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257604, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257602, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257601, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257583, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257589, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257587, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257586, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257585, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257584, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257615, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257614, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257613, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257618, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257617, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257581, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(259137, 0, 32, 0, 0), -- The End Is Coming!
(257705, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257712, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257692, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257747, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257710, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257708, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257707, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257706, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257703, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257702, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257701, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257698, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257696, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257695, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257694, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257693, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257691, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257746, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257709, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257704, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257700, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257699, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257697, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257781, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257780, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257779, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257778, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257777, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257776, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257743, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257742, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257741, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257740, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257739, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257738, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257737, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257736, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257735, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257734, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257733, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257732, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257731, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257730, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257729, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257728, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257759, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257758, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257757, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257756, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257755, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257754, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257753, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257752, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257751, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257750, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257749, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257748, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257745, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257744, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257711, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257727, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257726, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257725, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257724, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257723, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257722, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257721, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257720, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257719, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257718, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257717, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257716, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257715, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257714, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257713, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257679, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257678, 0, 32, 0, 0), -- Noodle Cart
(257677, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257676, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257675, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257674, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257673, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257672, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257671, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257670, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257669, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257668, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257667, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257666, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257665, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257664, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257690, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257689, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257687, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257685, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257684, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257683, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257682, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257681, 0, 32, 0, 0), -- Bubbling Pot
(257647, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257646, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257645, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257644, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257643, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257642, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257641, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257640, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257639, 0, 32, 0, 0), -- Anvil
(257638, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257637, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257636, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257635, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257634, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257633, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257632, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257663, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257662, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257661, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257660, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257659, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257658, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257657, 0, 32, 0, 0), -- Forge
(257656, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(259146, 0, 32, 0, 0), -- Goblin Machine
(257655, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257654, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257653, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257652, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257651, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257650, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257649, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257648, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257836, 0, 1048608, 0, 0), -- Horde Battleship
(257835, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257834, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257833, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257832, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257631, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257831, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257630, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257830, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257629, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257829, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257628, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257828, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257627, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257827, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257626, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257826, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257825, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257824, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257623, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257622, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257621, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257620, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257619, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257807, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257806, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257805, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257804, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257803, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257802, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257801, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257800, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257799, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257798, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257797, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257796, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257795, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257794, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257793, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257792, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257823, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257822, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257821, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257820, 0, 32, 0, 0); -- 7.0 Pre-Launch - Orgrimmar - Template Object

INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(257819, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257818, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257817, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257816, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257815, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257814, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257813, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257812, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257811, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257810, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257809, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257808, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(259138, 0, 32, 0, 0), -- Goblin Forge
(258975, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(258974, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(254942, 0, 1048608, 0, 0), -- Horde Battleship
(257775, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(259121, 0, 32, 0, 0), -- Gregg's Rocks
(257774, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257773, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257772, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257771, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257770, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257769, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257768, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257767, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257766, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257765, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257764, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257763, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257762, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257761, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257760, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257791, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257790, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257789, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(259120, 0, 32, 0, 0), -- Gregg's Cart
(257788, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257787, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257786, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257785, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257784, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257783, 0, 32, 0, 0), -- 7.0 Pre-Launch - Orgrimmar - Template Object
(257782, 0, 32, 0, 0); -- 7.0 Pre-Launch - Orgrimmar - Template Object

UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=248819; -- Legion Cage
UPDATE `gameobject_template_addon` SET `flags`=49 WHERE `entry`=240535; -- Legion Cage
UPDATE `gameobject_template_addon` SET `faction`=94, `flags`=262145, `WorldEffectID`=2100 WHERE `entry`=237191; -- Garrison Cache
UPDATE `gameobject_template_addon` SET `faction`=2780, `flags`=32 WHERE `entry`=240194; -- Spire of Woe
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=251195; -- Keg of Armor Polish
UPDATE `gameobject_template_addon` SET `flags`=2637856, `WorldEffectID`=2437 WHERE `entry`=255931; -- Cauldron of Mojo
UPDATE `gameobject_template_addon` SET `flags`=262176 WHERE `entry`=255930; -- Sun Sphere
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213707; -- Bar
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213704; -- Banner
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213702; -- Banner
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213703; -- Banner
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8830 WHERE `entry`=278347; -- Warchief's Command Board
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=213698; -- Mailbox
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213697; -- Bench
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213990; -- Paladin
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=213727; -- Mailbox
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213991; -- Priest
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213989; -- Monk
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213986; -- Deathknight
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213987; -- Druid
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213984; -- Rogue
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213985; -- Shaman
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213716; -- Banner
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213715; -- Banner
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=213728; -- Mailbox
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=214728; -- Mage
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=214729; -- Warlock
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=214727; -- Warrior
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=214176; -- Mailbox
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213676; -- Anvil
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213675; -- Tongs
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=213682; -- Mailbox
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=213683; -- Mailbox
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=213708; -- Mailbox
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213706; -- Banner
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=228572; -- Fireweed
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=232521; -- Small Fire
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232524; -- Huge Fire
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232513; -- Large Fire
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=234473; -- Campaign Contributions

DELETE FROM `quest_offer_reward` WHERE `ID` IN (40518 /*-Unknown-*/, 44281 /*-Unknown-*/, 43926 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(40518, 1, 1, 0, 0, 0, 0, 0, 0, 'Glad to see you back on your feet, $n. Many good soldiers who sailed for the Broken Shore were not so fortunate.', 38134), -- -Unknown-
(44281, 1, 1, 0, 0, 0, 0, 0, 0, 'You look quite prepared for battle. Do not let the bloodlust overtake you out there.$b$bThe Warchief wishes to present you with this ring before you head to war. May you return with the heads of many demons.', 38134), -- -Unknown-
(43926, 1, 1, 0, 0, 0, 0, 0, 0, 'The ships are leaving from the dock in Bladefist Bay.$B$BBefore you leave, prepare yourself. I have the feeling that this fight won\'t be an easy one.', 38134); -- -Unknown-

UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=32674; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=32674; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=36062; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=35298; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=35298; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=35091; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=36428; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=35211; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=35090; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=35089; -- -Unknown-

DELETE FROM `quest_poi` WHERE (`QuestID`=35298 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=35298 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=35298 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=35089 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=35089 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=35089 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=35089 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(35298, 0, 2, 32, 0, 0, 1116, 542, 0, 0, 0, 0, 0, 887195, 0, 38134), -- -Unknown-
(35298, 0, 1, 1, 273955, 81567, 1116, 542, 0, 0, 0, 0, 0, 900043, 0, 38134), -- -Unknown-
(35298, 0, 0, -1, 0, 0, 1116, 542, 0, 0, 0, 0, 0, 901300, 0, 38134), -- -Unknown-
(35089, 1, 3, 32, 0, 0, 1116, 542, 0, 0, 0, 0, 0, 887921, 0, 38134), -- -Unknown-
(35089, 0, 2, 32, 0, 0, 1116, 542, 0, 0, 0, 0, 0, 895273, 0, 38134), -- -Unknown-
(35089, 0, 1, 0, 273434, 112906, 1116, 542, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(35089, 0, 0, -1, 0, 0, 1116, 542, 0, 0, 0, 0, 0, 887921, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=40518 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=40518 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=40518 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=0 AND `Idx1`=12); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=0 AND `Idx1`=11); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=5 AND `Idx1`=10); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=4 AND `Idx1`=9); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=3 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=2 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=1 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=43926 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=43926 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35211 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35211 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35211 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=32674 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=35298 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=35298 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=35298 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=35089 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=35089 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=35089 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=35089 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=35089 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=35089 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=35089 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=35089 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=35089 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(35298, 2, 0, -2341, 1137, 22, 38134), -- -Unknown-
(35298, 1, 0, -2369, 1113, 28, 38134), -- -Unknown-
(35298, 0, 0, -1560, 948, 8, 38134), -- -Unknown-
(35089, 3, 0, -2367, 1116, 28, 38134), -- -Unknown-
(35089, 2, 0, -2346, 1137, 28, 38134), -- -Unknown-
(35089, 1, 5, -2220, 1029, 2, 38134), -- -Unknown-
(35089, 1, 4, -2282, 1120, 3, 38134), -- -Unknown-
(35089, 1, 3, -2258, 1186, 0, 38134), -- -Unknown-
(35089, 1, 2, -2199, 1138, 1, 38134), -- -Unknown-
(35089, 1, 1, -2164, 1070, 0, 38134), -- -Unknown-
(35089, 1, 0, -2194, 1013, 1, 38134), -- -Unknown-
(35089, 0, 0, -2367, 1116, 28, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=40518 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=40518 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=40518 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=12 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=11 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=10 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=9 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=44281 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=43926 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=43926 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36428 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35211 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35211 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35211 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35211 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35211 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35211 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35211 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35091 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35090 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=32674 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (40522 /*-Unknown-*/, 40518 /*-Unknown-*/, 44281 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(40522, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(40518, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(44281, 1, 1, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=35298; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=35298; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=36428; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=35211; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=35091; -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=34461;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(34461, 0, 0, 0, 0, 'You pick the plot, we\'ll build the spot!', 38134); -- -Unknown-

DELETE FROM `spell_target_position` WHERE (`ID`=333607 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(333607, 0, 2147, -642.8800048828125, 2208.25, 550.71002197265625, 38134); -- Spell: 333607 ([DNT] Teleport: Acherus) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=200282 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=198175 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=208517 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=224997 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=227792 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=224983 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `MapID`=1152, `PositionX`=5560.39990234375, `PositionY`=4507.7001953125, `PositionZ`=132.6699981689453125 WHERE (`ID`=171253 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=225152 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=121862 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (100720 /*100720 (Trade Prince Gallywix)*/, 100405 /*100405 (Baine Bloodhoof) - Threat 10000%*/, 100660 /*100660 (Lor'themar Theron)*/, 112706 /*112706 (Aethas Sunreaver)*/, 100406 /*100406 (Ji Firepaw) - Wounded*/, 100442 /*100442 (Vol'jin) - Ride Vehicle Hardcoded, Fel-poisoned, Threat 5000%*/, 113112 /*113112 (Vol'jin)*/, 111935 /*111935 (Orgrimmar Grunt)*/, 100407 /*100407 (Lady Sylvanas Windrunner)*/, 100467 /*100467 (Forsaken Deathguard)*/, 11155 /*11155 (Brown Skeletal Horse)*/, 11154 /*11154 (Blue Skeletal Horse)*/, 100684 /*100684 (Silvermoon Citizen)*/, 12147 /*12147 (Riding Kodo (White))*/, 12146 /*12146 (Riding Kodo (Olive))*/, 100636 /*100636 (High Overlord Saurfang)*/, 100662 /*100662 (Denizen of Undercity)*/, 61751 /*61751 (Hare)*/, 100664 /*100664 (Thunder Bluff Native)*/, 100679 /*100679 (Citizen of Kezan)*/, 3197 /*3197 (Burning Blade Fanatic)*/, 3198 /*3198 (Burning Blade Apprentice)*/, 100682 /*100682 (Silvermoon Citizen)*/, 100502 /*100502 (Concerned Citizen)*/, 100663 /*100663 (Sen'jin Villager)*/, 100453 /*100453 (Eitrigg)*/, 160527 /*160527 (Mak)*/, 160526 /*160526 (Neri Sharpfin)*/, 160530 /*160530 (Friend Pronk)*/, 160529 /*160529 (Vim Brineheart)*/, 160528 /*160528 (Poen Gillbrack)*/, 105176 /*105176 (Sathrovarr the Corruptor) - Portal-Spawned Demon Visual*/, 105169 /*105169 (Mephistroth) - Portal-Spawned Demon Visual*/, 105168 /*105168 (Anetheron) - Portal-Spawned Demon Visual*/, 105171 /*105171 (Mal'ganis) - Portal-Spawned Demon Visual*/, 105170 /*105170 (Balnazzar) - Portal-Spawned Demon Visual*/, 90688 /*90688 (Tichondrius the Darkener) - Portal-Spawned Demon Visual*/, 111079 /*111079 (Dantalionax) - Portal-Spawned Demon Visual*/, 111154 /*111154 (Malgalor) - Portal-Spawned Demon Visual*/, 91902 /*91902 (Brutallus) - Portal-Spawned Demon Visual*/, 105166 /*105166 (Gorgonnash) - Portal-Spawned Demon Visual*/, 105163 /*105163 (Destromath) - Portal-Spawned Demon Visual*/, 111089 /*111089 (Malinoth) - Portal-Spawned Demon Visual*/, 92558 /*92558 (Arkethrax) - Portal-Spawned Demon Visual*/, 111153 /*111153 (Aargoss) - Portal-Spawned Demon Visual*/, 111152 /*111152 (Grand Summoner Abraxeton) - Portal-Spawned Demon Visual*/, 105192 /*105192 (Caria Felsoul) - Portal-Spawned Demon Visual*/, 105188 /*105188 (Cordana Felsong) - Portal-Spawned Demon Visual*/, 105190 /*105190 (Varedis Felsoul) - Portal-Spawned Demon Visual*/, 105185 /*105185 (Overseer Lykill) - Portal-Spawned Demon Visual*/, 105187 /*105187 (Azoran) - Portal-Spawned Demon Visual*/, 105186 /*105186 (Oublion) - Portal-Spawned Demon Visual*/, 105181 /*105181 (Lady Sacrolash) - Portal-Spawned Demon Visual*/, 105180 /*105180 (Grand Warlock Alythess) - Portal-Spawned Demon Visual*/, 105182 /*105182 (Gravax the Desecrator) - Portal-Spawned Demon Visual*/, 105179 /*105179 (Lord Jaraxxus) - Portal-Spawned Demon Visual*/, 111173 /*111173 (Soulchaser) - Portal-Spawned Demon Visual*/, 105189 /*105189 (Doomlord Kazrok) - Portal-Spawned Demon Visual*/, 105174 /*105174 (Smashspite the Hateful) - Portal-Spawned Demon Visual*/, 111088 /*111088 (Lord Perdition) - Portal-Spawned Demon Visual*/, 111167 /*111167 (Lochaber) - Portal-Spawned Demon Visual*/, 105197 /*105197 (Felwing) - Portal-Spawned Demon Visual*/, 105196 /*105196 (Brogozog) - Portal-Spawned Demon Visual*/, 111175 /*111175 (The Overseer) - Portal-Spawned Demon Visual*/, 111174 /*111174 (Vaultwarden Umbra) - Portal-Spawned Demon Visual*/, 105183 /*105183 (Lord Kra'vos) - Portal-Spawned Demon Visual*/, 105175 /*105175 (Blerg) - Portal-Spawned Demon Visual*/, 105167 /*105167 (Imp Mother Fecunda) - Portal-Spawned Demon Visual*/, 111085 /*111085 (Geth'xun) - Portal-Spawned Demon Visual*/, 111087 /*111087 (Hakkar the Houndmaster) - Portal-Spawned Demon Visual*/, 111157 /*111157 (Pilik) - Portal-Spawned Demon Visual*/, 111156 /*111156 (Fel Lord Dakuur) - Portal-Spawned Demon Visual*/, 105165 /*105165 (Felgard Legionnaire) - Portal-Spawned Demon Visual*/, 105164 /*105164 (Felgard Legionnaire) - Portal-Spawned Demon Visual*/, 114280 /*114280 (Vizuul the Twisted) - Fel Dissolve In*/, 105205 /*105205 (Mo'arg Spinebreaker) - Portal-Spawned Demon Visual*/, 105206 /*105206 (Wrathguard Dreadblade) - Portal-Spawned Demon Visual*/, 105199 /*105199 (Felstalker Dreadhound) - Portal-Spawned Demon Visual*/, 105200 /*105200 (Felguard Invader) - Portal-Spawned Demon Visual*/, 111074 /*111074 (Grinning Shadowstalker) - Portal-Spawned Demon Visual*/, 92801 /*92801 (Winged Nightmare)*/, 114753 /*114753 (Gorgoloth)*/, 114754 /*114754 (Mazgoroth)*/, 114760 /*114760 (Harbinger Faraleth)*/, 114763 /*114763 (Darkmagus Drazzok)*/, 114756 /*114756 (Dread Knight Zak'gal)*/, 114758 /*114758 (Flamecaller Vezrah)*/, 114755 /*114755 (Fel Lord Kaz'ral)*/, 114757 /*114757 (Flameweaver Verathix)*/, 114764 /*114764 (Darkmagus Falo'reth)*/, 114759 /*114759 (Harbinger Drel'nathar)*/, 114761 /*114761 (Arch Magus Velysra)*/, 114762 /*114762 (Arch Magus Zyrel)*/, 114469 /*114469 (Exodar Vindicator)*/, 92122 /*92122 (Gnomeregan Tinkerer)*/, 110941 /*110941 (Desiccated Crusader) - Permanent Feign Death*/, 113129 /*113129 (Fel Lava) - Summon Fire Dogs*/, 105217 /*105217 (Argent Dawnbringer) - Permanent Feign Death (Burned, Fel)*/, 90516 /*90516 (Mo'arg Painbringer)*/, 90677 /*90677 (Wrathguard Dreadblade) - Dual Wield*/, 105203 /*105203 (Felguard Invader)*/, 113054 /*113054 (Diathorus the Seeker) - Legion Bye*/, 113055 /*113055 (Lord Banehollow) - Legion Bye*/, 90544 /*90544 (Krosus) - Krosus Emerge*/, 113056 /*113056 (Solenor the Slayer) - Legion Bye*/, 113058 /*113058 (Fel Lord Volak)*/, 113057 /*113057 (Fel Lord Durkan)*/, 102706 /*102706 (Grinning Shadowstalker)*/, 113053 /*113053 (Mother Sepestra) - Fel Rain*/, 102696 /*102696 (Felslag Imp)*/, 90506 /*90506 (Felfire Imp)*/, 113059 /*113059 (Fel Lord Garzan)*/, 102702 /*102702 (Wrathguard Dreadblade) - Dual Wield*/, 91970 /*91970 (Felguard Invader)*/, 105172 /*105172 (Winged Nightmare)*/, 97510 /*97510 (Soulbound Destructor) - Dual Wield*/, 92564 /*92564 (Mo'arg Painbringer) - Portal-Spawned Demon Visual*/, 101103 /*101103 (Command Ship) - Finale Ship VFX*/, 112976 /*112976 (Argent Lightbringer) - Dying*/, 91967 /*91967 (Infernal Siegebreaker) - Fel Immolation*/, 102701 /*102701 (Mo'arg Painbringer)*/, 94190 /*94190 (Burning Sentry)*/, 94189 /*94189 (Living Felblaze)*/, 94191 /*94191 (Burning Terrorhound)*/, 112977 /*112977 (Argent Lightbringer) - Permanent Feign Death*/, 110617 /*110617 (Shadowsworn Harbinger)*/, 110616 /*110616 (Dark Worshipper) - Summon Lesser Demons*/, 97527 /*97527 (Argent Lightbringer) - Penance*/, 97528 /*97528 (Argent Lightbringer)*/, 100959 /*100959 (Unattended Cannon)*/, 93708 /*93708 (Thunder Bluff Brave) - Permanent Feign Death (Flies)*/, 97525 /*97525 (Thunder Bluff Brave) - Permanent Feign Death (Flies)*/, 101667 /*101667 (Shielded Anchor)*/, 90705 /*90705 (Dread Commander Arganoth)*/, 101057 /*101057 (Gilnean Royal Guard) - Global - Replace Stand With Ready1h (Spawn), Permanent Feign Death (Burned, Fel)*/, 80221 /*80221*/, 83947 /*83947 (Kimzee Pinchwhistle) - Dual Wield*/, 76872 /*76872*/, 80436 /*80436*/, 81688 /*81688*/, 74808 /*74808*/, 80437 /*80437*/, 79407 /*79407*/, 79619 /*79619*/, 88649 /*88649 (Draka)*/, 80151 /*80151*/, 89262 /*89262*/, 83858 /*83858*/, 79774 /*79774 - Garrison Combat Throttle*/, 80776 /*80776 - Garrison Ambient, Axe Sticks, Near Bull, 10 oclock*/, 80772 /*80772 (Sawame Brightburn)*/, 81166 /*81166*/, 79740 /*79740*/, 76928 /*76928 (Kraank)*/, 85882 /*85882*/, 80223 /*80223 (Lady Sena)*/, 80222 /*80222 (Mr. Pleeb)*/, 80440 /*80440*/, 78320 /*78320*/, 80432 /*80432*/, 83482 /*83482*/, 84967 /*84967*/, 79916 /*79916*/, 80438 /*80438*/, 79605 /*79605*/, 78487 /*78487 (Rokhan)*/, 79603 /*79603*/, 80600 /*80600*/, 78466 /*78466 (Gazlowe)*/, 80299 /*80299 - Garrison Combat Throttle*/, 79925 /*79925*/, 76411 /*76411 (Farseer Drek'Thar) - Bringing Down the Canyon (Earth)*/, 80288 /*80288*/, 79781 /*79781 - Garrison Combat Throttle*/, 86470 /*86470*/, 90712 /*90712 (Earthen Ring Shaman) - Permanent Feign Death (Burned, Fel)*/, 109604 /*109604 (Felguard Legionnaire)*/, 114466 /*114466 (Darnassus Sentinel)*/, 113037 /*113037 (Fel Lord Darakk) - Spawn - Replace 2H with 2HL*/, 113036 /*113036 (Fel Lord Razzar) - Spawn - Replace 2H with 2HL*/, 113038 /*113038 (Fel Lord Kurrz) - Spawn - Replace 2H with 2HL*/, 97496 /*97496 (Kirin Tor Battle-Mage)*/, 114863 /*114863 (General Purpose Bunny JMF (Look 2 - Flying, Huge AOI))*/, 93719 /*93719 (Fel Commander Azgalor)*/, 112879 /*112879 (Horde Priest) - Holy Channeling*/, 114479 /*114479 (Silvermoon Blood Knight)*/, 92061 /*92061 (Cannon)*/, 108990 /*108990 (Stormwind Gryphon) - Permanent Feign Death (Burned, Fel)*/, 93704 /*93704 (Darkspear Headhunter) - Permanent Feign Death (Burned, Fel)*/, 109591 /*109591 (Felguard Legionnaire)*/, 113290 /*113290 (Riding Bat) - Permanent Feign Death (Burned, Fel)*/, 112921 /*112921 (Bilgewater Blastmaster)*/, 97521 /*97521 (Earthen Ring Shaman)*/, 92586 /*92586 (Ironforge Cannoneer)*/, 109587 /*109587 (Fel Lord Zardak) - Spawn - Replace 2H with 2HL*/, 91353 /*91353 (Kirin Tor Battle-Mage)*/, 72973 /*72973 (General Purpose Bunny JMF (Look 2, Huge AOI))*/, 90686 /*90686 (Felstalker Dreadhound)*/, 109592 /*109592 (Felguard Legionnaire)*/, 91704 /*91704 (Anchoring Crystal) - Ride Vehicle*/, 90717 /*90717 (Genn Greymane) - Alliance Hero, Threat 5000%*/, 90714 /*90714 (Lady Jaina Proudmoore) - Alliance Hero, Threat 5000%*/, 90711 /*90711 (Thrall) - Horde Hero, Threat 5000%*/, 90708 /*90708 (Vol'jin) - Horde Hero, Threat 5000%*/, 91951 /*91951 (Highlord Tirion Fordring)*/, 90713 /*90713 (King Varian Wrynn) - Alliance Hero, Threat 10000%*/, 90709 /*90709 (Lady Sylvanas Windrunner) - Horde Hero, Threat 5000%*/, 90710 /*90710 (Baine Bloodhoof) - Horde Hero, Threat 10000%*/, 112924 /*112924 (Captain Russo)*/, 94276 /*94276 (Gul'dan)*/, 90716 /*90716 (Gelbin Mekkatorque) - Alliance Hero, Threat 5000%*/, 109341 /*109341 (General Purpose Bunny JMF)*/, 114250 /*114250 (Gelbin Mekkatorque) - Ride Vehicle Hardcoded*/, 101632 /*101632 (Mo'arg Painbringer) - Permanent Feign Death (Flies)*/, 90525 /*90525 (Eredar Chaos Guard)*/, 113341 /*113341 (Deck Hand)*/, 112923 /*112923 (Du'pre)*/, 113118 /*113118 (Captain Russo)*/, 113151 /*113151 (Fo'rum the Postmaker)*/, 113547 /*113547 (Stone Guard Mukar)*/, 113616 /*113616 (Garyl)*/, 113615 /*113615 (Ravika)*/, 112922 /*112922 (Cannon-In-A-Box)*/, 114134 /*114134 (Doomsayer)*/, 112920 /*112920 (Dark Ranger) - Global - Replace Stand With Ready Bow (Spawn)*/, 114132 /*114132 (Doomsayer)*/, 113959 /*113959 (Shappa)*/, 113947 /*113947 (Maska)*/, 114133 /*114133 (Doomsayer)*/, 113960 /*113960 (Arcanist Druk'rog)*/, 113946 /*113946 (Karn Steelhoof)*/, 113945 /*113945 (Omril Keenedge) - Dual Wield*/, 113544 /*113544 (Neejala)*/, 113542 /*113542 (Marius Sunshard)*/, 114106 /*114106 (Sergeant Grimjaw)*/, 113545 /*113545 (Dawn Mercurus)*/, 113543 /*113543 (Annix Strifesprocket)*/, 113546 /*113546 (Yaalo)*/, 113961 /*113961 (Pinkee Rizzo) - Dual Wield*/, 113948 /*113948 (Arienne Black)*/, 113949 /*113949 (Rizza Brassrokkit) - Dual Wield*/, 113950 /*113950 (Lonan) - Dual Wield*/, 113951 /*113951 (Sahale)*/, 113955 /*113955 (Utona Wolfeye)*/, 113956 /*113956 (Taela Shatterborne)*/, 113953 /*113953 (Faala)*/, 113957 /*113957 (Ja'kala)*/, 14729 /*14729 (Ralston Farnsley)*/, 113952 /*113952 (Aila Dourblade) - Dual Wield*/, 113958 /*113958 (Handel Shadereaver)*/, 113954 /*113954 (Argonis Solheart)*/, 114107 /*114107 (Lan'veros Furybrand)*/, 114108 /*114108 (Merhean Sunfall)*/, 113541 /*113541 (Seleria Dawncaller)*/, 114135 /*114135 (Bilgewater Blastmaster)*/, 114136 /*114136 (Bilgewater Blastmaster)*/, 113550 /*113550 (Rakkaha)*/, 113549 /*113549 (Sulaka)*/, 113551 /*113551 (Ja'kala)*/, 113548 /*113548 (Mojo'kai)*/, 113539 /*113539 (Orgek Ironhand)*/, 97526 /*97526 (Deathguard Elite) - Dual Wield, Cosmetic - Drink Tankard*/, 114105 /*114105 (Kinja)*/, 113034 /*113034 (Darkspear Headhunter) - Global - Replace Stand With Ready1h (Spawn)*/, 113997 /*113997 (Megaton)*/, 114114 /*114114 (Gregg)*/, 113540 /*113540 (Liu-So) - Dual Wield*/, 114068 /*114068 (Ju-Shan)*/, 113374 /*113374 (Horde Recruit)*/, 113375 /*113375 (Horde Recruit)*/, 113373 /*113373 (Horde Recruit)*/, 114067 /*114067 (Darkspear Bat Rider)*/, 113377 /*113377 (Horde Recruit)*/, 113331 /*113331 (Horde Recruit)*/, 113291 /*113291 (Wind Rider)*/, 113376 /*113376 (Horde Recruit) - Cosmetic - Drink Tankard*/, 113380 /*113380 (Horde Recruit)*/, 114066 /*114066 (Orgrimmar Wind Rider)*/, 113381 /*113381 (Horde Recruit)*/, 55336 /*55336*/, 85798 /*85798 (Golden Dawnfeather)*/, 85007 /*85007 (Thicket Skitterer)*/, 80589 /*80589*/, 82512 /*82512*/, 82558 /*82558*/, 82553 /*82553*/, 83797 /*83797*/, 82511 /*82511*/, 82508 /*82508*/, 83930 /*83930*/, 84054 /*84054*/, 82568 /*82568*/, 83786 /*83786*/, 82183 /*82183*/, 83921 /*83921*/, 82516 /*82516*/, 82566 /*82566 - Drink Tray*/, 83902 /*83902*/, 84093 /*84093*/, 82467 /*82467 (Krixel Pinchwhistle)*/, 82468 /*82468 (Kimzee Pinchwhistle)*/, 82567 /*82567 - Ride Vehicle Hardcoded*/, 82552 /*82552*/, 83744 /*83744 (Rescued Crewman)*/, 82554 /*82554*/, 83884 /*83884 - Pepe*/, 83703 /*83703 - Flamethrower Backpack*/, 83854 /*83854*/, 83938 /*83938*/, 83920 /*83920*/, 82555 /*82555*/, 88587 /*88587 - Mod Scale 95-120%*/, 83944 /*83944 - Invisibility and Stealth Detection*/, 83908 /*83908*/, 83891 /*83891 (Gearworks Crab)*/, 84856 /*84856*/, 82243 /*82243*/, 87087 /*87087 (Bulbapore)*/, 81135 /*81135 - Permanent Feign Death (Stun, Untrackable, Immune)*/, 81288 /*81288 - Mod Scale 95-120%*/, 82272 /*82272*/, 81138 /*81138*/, 88578 /*88578*/, 89356 /*89356*/, 85403 /*85403*/, 88426 /*88426*/, 81168 /*81168*/, 61312 /*61312 (Strand Crab)*/, 81567 /*81567 (Repaired Flying Machine)*/, 85793 /*85793 (Cured Goblin)*/, 84887 /*84887 - Betsi Boombasket*/, 85325 /*85325 - Cosmetic - Mushroom Infection*/, 82253 /*82253*/, 88419 /*88419*/, 81632 /*81632 (Firebomb)*/, 81566 /*81566*/, 81978 /*81978*/, 82265 /*82265*/, 81443 /*81443 (Krixel Pinchwhistle)*/, 81184 /*81184 - Cosmetic - Mushroom Infection*/, 82182 /*82182*/, 85647 /*85647 - Wrecked Hotrod State*/, 85417 /*85417 - Mod Scale 95-120%*/, 88481 /*88481*/, 81183 /*81183 - Cosmetic - Mushroom Infection*/, 81524 /*81524*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(100720, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 100720 (Trade Prince Gallywix)
(100405, 0, 0, 0, 0, 0, 0, 0, 0, '222585'), -- 100405 (Baine Bloodhoof) - Threat 10000%
(100660, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 100660 (Lor'themar Theron)
(112706, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112706 (Aethas Sunreaver)
(100406, 0, 0, 0, 0, 0, 0, 0, 0, '197704'), -- 100406 (Ji Firepaw) - Wounded
(100442, 0, 0, 0, 1, 0, 0, 0, 0, '46598 197702 222584'), -- 100442 (Vol'jin) - Ride Vehicle Hardcoded, Fel-poisoned, Threat 5000%
(113112, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113112 (Vol'jin)
(111935, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111935 (Orgrimmar Grunt)
(100407, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100407 (Lady Sylvanas Windrunner)
(100467, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100467 (Forsaken Deathguard)
(11155, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 11155 (Brown Skeletal Horse)
(11154, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 11154 (Blue Skeletal Horse)
(100684, 0, 18696, 0, 1, 0, 0, 0, 0, ''), -- 100684 (Silvermoon Citizen)
(12147, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 12147 (Riding Kodo (White))
(12146, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 12146 (Riding Kodo (Olive))
(100636, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100636 (High Overlord Saurfang)
(100662, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100662 (Denizen of Undercity)
(61751, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61751 (Hare)
(100664, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 100664 (Thunder Bluff Native)
(100679, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 100679 (Citizen of Kezan)
(3197, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 3197 (Burning Blade Fanatic)
(3198, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 3198 (Burning Blade Apprentice)
(100682, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 100682 (Silvermoon Citizen)
(100502, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 100502 (Concerned Citizen)
(100663, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 100663 (Sen'jin Villager)
(100453, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100453 (Eitrigg)
(160527, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160527 (Mak)
(160526, 0, 90766, 0, 1, 0, 0, 0, 0, ''), -- 160526 (Neri Sharpfin)
(160530, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 160530 (Friend Pronk)
(160529, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 160529 (Vim Brineheart)
(160528, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 160528 (Poen Gillbrack)
(105176, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105176 (Sathrovarr the Corruptor) - Portal-Spawned Demon Visual
(105169, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105169 (Mephistroth) - Portal-Spawned Demon Visual
(105168, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105168 (Anetheron) - Portal-Spawned Demon Visual
(105171, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105171 (Mal'ganis) - Portal-Spawned Demon Visual
(105170, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105170 (Balnazzar) - Portal-Spawned Demon Visual
(90688, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 90688 (Tichondrius the Darkener) - Portal-Spawned Demon Visual
(111079, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111079 (Dantalionax) - Portal-Spawned Demon Visual
(111154, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111154 (Malgalor) - Portal-Spawned Demon Visual
(91902, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 91902 (Brutallus) - Portal-Spawned Demon Visual
(105166, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105166 (Gorgonnash) - Portal-Spawned Demon Visual
(105163, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105163 (Destromath) - Portal-Spawned Demon Visual
(111089, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111089 (Malinoth) - Portal-Spawned Demon Visual
(92558, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 92558 (Arkethrax) - Portal-Spawned Demon Visual
(111153, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111153 (Aargoss) - Portal-Spawned Demon Visual
(111152, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111152 (Grand Summoner Abraxeton) - Portal-Spawned Demon Visual
(105192, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105192 (Caria Felsoul) - Portal-Spawned Demon Visual
(105188, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105188 (Cordana Felsong) - Portal-Spawned Demon Visual
(105190, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105190 (Varedis Felsoul) - Portal-Spawned Demon Visual
(105185, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105185 (Overseer Lykill) - Portal-Spawned Demon Visual
(105187, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105187 (Azoran) - Portal-Spawned Demon Visual
(105186, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105186 (Oublion) - Portal-Spawned Demon Visual
(105181, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105181 (Lady Sacrolash) - Portal-Spawned Demon Visual
(105180, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105180 (Grand Warlock Alythess) - Portal-Spawned Demon Visual
(105182, 0, 0, 50331648, 1, 0, 0, 0, 0, '200312'), -- 105182 (Gravax the Desecrator) - Portal-Spawned Demon Visual
(105179, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105179 (Lord Jaraxxus) - Portal-Spawned Demon Visual
(111173, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111173 (Soulchaser) - Portal-Spawned Demon Visual
(105189, 0, 0, 50331648, 1, 0, 0, 0, 0, '200312'), -- 105189 (Doomlord Kazrok) - Portal-Spawned Demon Visual
(105174, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105174 (Smashspite the Hateful) - Portal-Spawned Demon Visual
(111088, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111088 (Lord Perdition) - Portal-Spawned Demon Visual
(111167, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111167 (Lochaber) - Portal-Spawned Demon Visual
(105197, 0, 0, 50331648, 1, 0, 0, 0, 0, '200312'), -- 105197 (Felwing) - Portal-Spawned Demon Visual
(105196, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105196 (Brogozog) - Portal-Spawned Demon Visual
(111175, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111175 (The Overseer) - Portal-Spawned Demon Visual
(111174, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111174 (Vaultwarden Umbra) - Portal-Spawned Demon Visual
(105183, 0, 0, 50331648, 1, 0, 0, 0, 0, '200312'), -- 105183 (Lord Kra'vos) - Portal-Spawned Demon Visual
(105175, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105175 (Blerg) - Portal-Spawned Demon Visual
(105167, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105167 (Imp Mother Fecunda) - Portal-Spawned Demon Visual
(111085, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111085 (Geth'xun) - Portal-Spawned Demon Visual
(111087, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111087 (Hakkar the Houndmaster) - Portal-Spawned Demon Visual
(111157, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111157 (Pilik) - Portal-Spawned Demon Visual
(111156, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111156 (Fel Lord Dakuur) - Portal-Spawned Demon Visual
(105165, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105165 (Felgard Legionnaire) - Portal-Spawned Demon Visual
(105164, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105164 (Felgard Legionnaire) - Portal-Spawned Demon Visual
(114280, 0, 0, 0, 1, 0, 0, 0, 0, '211762'), -- 114280 (Vizuul the Twisted) - Fel Dissolve In
(105205, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105205 (Mo'arg Spinebreaker) - Portal-Spawned Demon Visual
(105206, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105206 (Wrathguard Dreadblade) - Portal-Spawned Demon Visual
(105199, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105199 (Felstalker Dreadhound) - Portal-Spawned Demon Visual
(105200, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 105200 (Felguard Invader) - Portal-Spawned Demon Visual
(111074, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 111074 (Grinning Shadowstalker) - Portal-Spawned Demon Visual
(92801, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 92801 (Winged Nightmare)
(114753, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114753 (Gorgoloth)
(114754, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114754 (Mazgoroth)
(114760, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114760 (Harbinger Faraleth)
(114763, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114763 (Darkmagus Drazzok)
(114756, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114756 (Dread Knight Zak'gal)
(114758, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114758 (Flamecaller Vezrah)
(114755, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114755 (Fel Lord Kaz'ral)
(114757, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114757 (Flameweaver Verathix)
(114764, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114764 (Darkmagus Falo'reth)
(114759, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114759 (Harbinger Drel'nathar)
(114761, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114761 (Arch Magus Velysra)
(114762, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114762 (Arch Magus Zyrel)
(114469, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114469 (Exodar Vindicator)
(92122, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 92122 (Gnomeregan Tinkerer)
(110941, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 110941 (Desiccated Crusader) - Permanent Feign Death
(113129, 0, 0, 0, 1, 0, 0, 0, 0, '225175'), -- 113129 (Fel Lava) - Summon Fire Dogs
(105217, 0, 0, 33816576, 1, 0, 0, 0, 0, '186571'), -- 105217 (Argent Dawnbringer) - Permanent Feign Death (Burned, Fel)
(90516, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 90516 (Mo'arg Painbringer)
(90677, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 90677 (Wrathguard Dreadblade) - Dual Wield
(105203, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105203 (Felguard Invader)
(113054, 0, 0, 0, 1, 0, 0, 0, 0, '208511'), -- 113054 (Diathorus the Seeker) - Legion Bye
(113055, 0, 0, 0, 1, 0, 0, 0, 0, '208511'), -- 113055 (Lord Banehollow) - Legion Bye
(90544, 0, 0, 50331648, 1, 0, 1455, 0, 0, '208495'), -- 90544 (Krosus) - Krosus Emerge
(113056, 0, 0, 0, 1, 0, 0, 0, 0, '208511'), -- 113056 (Solenor the Slayer) - Legion Bye
(113058, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113058 (Fel Lord Volak)
(113057, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113057 (Fel Lord Durkan)
(102706, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102706 (Grinning Shadowstalker)
(113053, 0, 0, 50331648, 1, 0, 0, 0, 0, '218760'), -- 113053 (Mother Sepestra) - Fel Rain
(102696, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102696 (Felslag Imp)
(90506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 90506 (Felfire Imp)
(113059, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113059 (Fel Lord Garzan)
(102702, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 102702 (Wrathguard Dreadblade) - Dual Wield
(91970, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 91970 (Felguard Invader)
(105172, 0, 0, 50331648, 1, 0, 11403, 0, 0, ''), -- 105172 (Winged Nightmare)
(97510, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 97510 (Soulbound Destructor) - Dual Wield
(92564, 0, 0, 0, 1, 0, 0, 0, 0, '200312'), -- 92564 (Mo'arg Painbringer) - Portal-Spawned Demon Visual
(101103, 0, 0, 50331648, 1, 0, 0, 0, 0, '181979'), -- 101103 (Command Ship) - Finale Ship VFX
(112976, 0, 0, 0, 1, 0, 0, 0, 0, '208396'), -- 112976 (Argent Lightbringer) - Dying
(91967, 0, 0, 0, 1, 0, 0, 0, 0, '218765'), -- 91967 (Infernal Siegebreaker) - Fel Immolation
(102701, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102701 (Mo'arg Painbringer)
(94190, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 94190 (Burning Sentry)
(94189, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 94189 (Living Felblaze)
(94191, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 94191 (Burning Terrorhound)
(112977, 0, 0, 33554432, 1, 0, 0, 0, 0, '29266'), -- 112977 (Argent Lightbringer) - Permanent Feign Death
(110617, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110617 (Shadowsworn Harbinger)
(110616, 0, 0, 0, 1, 0, 0, 0, 0, '202936'), -- 110616 (Dark Worshipper) - Summon Lesser Demons
(97527, 0, 0, 0, 1, 0, 0, 0, 0, '172098'), -- 97527 (Argent Lightbringer) - Penance
(97528, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 97528 (Argent Lightbringer)
(100959, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100959 (Unattended Cannon)
(93708, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 93708 (Thunder Bluff Brave) - Permanent Feign Death (Flies)
(97525, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 97525 (Thunder Bluff Brave) - Permanent Feign Death (Flies)
(101667, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 101667 (Shielded Anchor)
(90705, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 90705 (Dread Commander Arganoth)
(101057, 0, 0, 262144, 1, 0, 0, 0, 0, '227771 186571'), -- 101057 (Gilnean Royal Guard) - Global - Replace Stand With Ready1h (Spawn), Permanent Feign Death (Burned, Fel)
(80221, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 80221
(83947, 0, 0, 0, 0, 0, 0, 0, 0, '42459'), -- 83947 (Kimzee Pinchwhistle) - Dual Wield
(76872, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 76872
(80436, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 80436
(81688, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 81688
(74808, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 74808
(80437, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 80437
(79407, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 79407
(79619, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 79619
(88649, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 88649 (Draka)
(80151, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 80151
(89262, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 89262
(83858, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83858
(79774, 0, 0, 0, 0, 0, 0, 0, 0, '178343'), -- 79774 - Garrison Combat Throttle
(80776, 0, 0, 0, 1, 0, 0, 0, 0, '163262'), -- 80776 - Garrison Ambient, Axe Sticks, Near Bull, 10 oclock
(80772, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 80772 (Sawame Brightburn)
(81166, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 81166
(79740, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 79740
(76928, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 76928 (Kraank)
(85882, 0, 0, 0, 258, 0, 0, 0, 0, ''), -- 85882
(80223, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 80223 (Lady Sena)
(80222, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 80222 (Mr. Pleeb)
(80440, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 80440
(78320, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 78320
(80432, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 80432
(83482, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 83482
(84967, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 84967
(79916, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 79916
(80438, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 80438
(79605, 0, 0, 5, 1, 0, 0, 0, 0, ''), -- 79605
(78487, 0, 0, 1, 256, 0, 0, 0, 0, ''), -- 78487 (Rokhan)
(79603, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 79603
(80600, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 80600
(78466, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 78466 (Gazlowe)
(80299, 0, 0, 0, 1, 0, 0, 0, 0, '178343'), -- 80299 - Garrison Combat Throttle
(79925, 0, 0, 5, 1, 0, 0, 0, 0, ''), -- 79925
(76411, 0, 0, 0, 1, 0, 0, 0, 0, '163071'), -- 76411 (Farseer Drek'Thar) - Bringing Down the Canyon (Earth)
(80288, 0, 0, 5, 0, 0, 0, 0, 0, ''), -- 80288
(79781, 0, 0, 0, 0, 0, 0, 0, 0, '178343'), -- 79781 - Garrison Combat Throttle
(86470, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 86470
(90712, 0, 0, 262144, 1, 0, 0, 0, 0, '186571'), -- 90712 (Earthen Ring Shaman) - Permanent Feign Death (Burned, Fel)
(109604, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109604 (Felguard Legionnaire)
(114466, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114466 (Darnassus Sentinel)
(113037, 0, 0, 0, 1, 0, 0, 0, 0, '218176'), -- 113037 (Fel Lord Darakk) - Spawn - Replace 2H with 2HL
(113036, 0, 0, 0, 1, 0, 0, 0, 0, '218176'), -- 113036 (Fel Lord Razzar) - Spawn - Replace 2H with 2HL
(113038, 0, 0, 0, 1, 0, 0, 0, 0, '218176'), -- 113038 (Fel Lord Kurrz) - Spawn - Replace 2H with 2HL
(97496, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 97496 (Kirin Tor Battle-Mage)
(114863, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 114863 (General Purpose Bunny JMF (Look 2 - Flying, Huge AOI))
(93719, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 93719 (Fel Commander Azgalor)
(112879, 0, 0, 0, 1, 0, 0, 0, 0, '51361'), -- 112879 (Horde Priest) - Holy Channeling
(114479, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114479 (Silvermoon Blood Knight)
(92061, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 92061 (Cannon)
(108990, 0, 0, 50593792, 1, 0, 0, 0, 0, '186571'), -- 108990 (Stormwind Gryphon) - Permanent Feign Death (Burned, Fel)
(93704, 0, 0, 262144, 1, 0, 0, 0, 0, '186571'), -- 93704 (Darkspear Headhunter) - Permanent Feign Death (Burned, Fel)
(109591, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109591 (Felguard Legionnaire)
(113290, 0, 0, 50593792, 1, 0, 0, 0, 0, '186571'), -- 113290 (Riding Bat) - Permanent Feign Death (Burned, Fel)
(112921, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 112921 (Bilgewater Blastmaster)
(97521, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 97521 (Earthen Ring Shaman)
(92586, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 92586 (Ironforge Cannoneer)
(109587, 0, 0, 0, 1, 0, 0, 0, 0, '218176'), -- 109587 (Fel Lord Zardak) - Spawn - Replace 2H with 2HL
(91353, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 91353 (Kirin Tor Battle-Mage)
(72973, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 72973 (General Purpose Bunny JMF (Look 2, Huge AOI))
(90686, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 90686 (Felstalker Dreadhound)
(109592, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109592 (Felguard Legionnaire)
(91704, 0, 0, 0, 1, 0, 0, 0, 0, '218009'), -- 91704 (Anchoring Crystal) - Ride Vehicle
(90717, 0, 0, 0, 1, 0, 0, 0, 0, '208359 222584'), -- 90717 (Genn Greymane) - Alliance Hero, Threat 5000%
(90714, 0, 0, 0, 1, 0, 0, 0, 0, '208359 222584'), -- 90714 (Lady Jaina Proudmoore) - Alliance Hero, Threat 5000%
(90711, 0, 0, 0, 1, 0, 0, 0, 0, '208489 222584'), -- 90711 (Thrall) - Horde Hero, Threat 5000%
(90708, 0, 0, 0, 1, 0, 0, 0, 0, '208489 222584'), -- 90708 (Vol'jin) - Horde Hero, Threat 5000%
(91951, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 91951 (Highlord Tirion Fordring)
(90713, 0, 0, 0, 1, 0, 0, 0, 0, '208359 222585'), -- 90713 (King Varian Wrynn) - Alliance Hero, Threat 10000%
(90709, 0, 0, 0, 1, 0, 0, 0, 0, '208489 222584'), -- 90709 (Lady Sylvanas Windrunner) - Horde Hero, Threat 5000%
(90710, 0, 0, 0, 1, 0, 0, 0, 0, '208489 222585'), -- 90710 (Baine Bloodhoof) - Horde Hero, Threat 10000%
(112924, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112924 (Captain Russo)
(94276, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 94276 (Gul'dan)
(90716, 0, 0, 0, 1, 0, 0, 0, 0, '208359 222584'), -- 90716 (Gelbin Mekkatorque) - Alliance Hero, Threat 5000%
(109341, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109341 (General Purpose Bunny JMF)
(114250, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 114250 (Gelbin Mekkatorque) - Ride Vehicle Hardcoded
(101632, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 101632 (Mo'arg Painbringer) - Permanent Feign Death (Flies)
(90525, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 90525 (Eredar Chaos Guard)
(113341, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113341 (Deck Hand)
(112923, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112923 (Du'pre)
(113118, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113118 (Captain Russo)
(113151, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 113151 (Fo'rum the Postmaker)
(113547, 0, 27245, 0, 257, 0, 0, 0, 0, ''), -- 113547 (Stone Guard Mukar)
(113616, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 113616 (Garyl)
(113615, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113615 (Ravika)
(112922, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112922 (Cannon-In-A-Box)
(114134, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114134 (Doomsayer)
(112920, 0, 0, 1, 0, 0, 0, 0, 0, '227774'), -- 112920 (Dark Ranger) - Global - Replace Stand With Ready Bow (Spawn)
(114132, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114132 (Doomsayer)
(113959, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113959 (Shappa)
(113947, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113947 (Maska)
(114133, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114133 (Doomsayer)
(113960, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113960 (Arcanist Druk'rog)
(113946, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113946 (Karn Steelhoof)
(113945, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 113945 (Omril Keenedge) - Dual Wield
(113544, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113544 (Neejala)
(113542, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113542 (Marius Sunshard)
(114106, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114106 (Sergeant Grimjaw)
(113545, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113545 (Dawn Mercurus)
(113543, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113543 (Annix Strifesprocket)
(113546, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113546 (Yaalo)
(113961, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 113961 (Pinkee Rizzo) - Dual Wield
(113948, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113948 (Arienne Black)
(113949, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 113949 (Rizza Brassrokkit) - Dual Wield
(113950, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 113950 (Lonan) - Dual Wield
(113951, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113951 (Sahale)
(113955, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113955 (Utona Wolfeye)
(113956, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113956 (Taela Shatterborne)
(113953, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113953 (Faala)
(113957, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113957 (Ja'kala)
(14729, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 14729 (Ralston Farnsley)
(113952, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 113952 (Aila Dourblade) - Dual Wield
(113958, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 113958 (Handel Shadereaver)

INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(113954, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113954 (Argonis Solheart)
(114107, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114107 (Lan'veros Furybrand)
(114108, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114108 (Merhean Sunfall)
(113541, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113541 (Seleria Dawncaller)
(114135, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114135 (Bilgewater Blastmaster)
(114136, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114136 (Bilgewater Blastmaster)
(113550, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113550 (Rakkaha)
(113549, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113549 (Sulaka)
(113551, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113551 (Ja'kala)
(113548, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113548 (Mojo'kai)
(113539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113539 (Orgek Ironhand)
(97526, 0, 0, 1, 1, 0, 0, 0, 0, '42459 42871'), -- 97526 (Deathguard Elite) - Dual Wield, Cosmetic - Drink Tankard
(114105, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114105 (Kinja)
(113034, 0, 0, 0, 1, 0, 0, 0, 0, '227771'), -- 113034 (Darkspear Headhunter) - Global - Replace Stand With Ready1h (Spawn)
(113997, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113997 (Megaton)
(114114, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114114 (Gregg)
(113540, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 113540 (Liu-So) - Dual Wield
(114068, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114068 (Ju-Shan)
(113374, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113374 (Horde Recruit)
(113375, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113375 (Horde Recruit)
(113373, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113373 (Horde Recruit)
(114067, 0, 1566, 50331648, 1, 0, 0, 0, 0, ''), -- 114067 (Darkspear Bat Rider)
(113377, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113377 (Horde Recruit)
(113331, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113331 (Horde Recruit)
(113291, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 113291 (Wind Rider)
(113376, 0, 0, 1, 1, 0, 0, 0, 0, '42871'), -- 113376 (Horde Recruit) - Cosmetic - Drink Tankard
(113380, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113380 (Horde Recruit)
(114066, 0, 29310, 50331648, 1, 0, 0, 0, 0, ''), -- 114066 (Orgrimmar Wind Rider)
(113381, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113381 (Horde Recruit)
(55336, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55336
(85798, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 85798 (Golden Dawnfeather)
(85007, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 85007 (Thicket Skitterer)
(80589, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 80589
(82512, 0, 0, 0, 1, 0, 3063, 0, 0, ''), -- 82512
(82558, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82558
(82553, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82553
(83797, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 83797
(82511, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82511
(82508, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82508
(83930, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83930
(84054, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 84054
(82568, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82568
(83786, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83786
(82183, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82183
(83921, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83921
(82516, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82516
(82566, 0, 0, 0, 1, 0, 0, 0, 0, '89842'), -- 82566 - Drink Tray
(83902, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 83902
(84093, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 84093
(82467, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82467 (Krixel Pinchwhistle)
(82468, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82468 (Kimzee Pinchwhistle)
(82567, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 82567 - Ride Vehicle Hardcoded
(82552, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82552
(83744, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83744 (Rescued Crewman)
(82554, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82554
(83884, 0, 0, 0, 1, 0, 0, 0, 0, '179795'), -- 83884 - Pepe
(83703, 0, 0, 0, 1, 0, 0, 0, 0, '158495'), -- 83703 - Flamethrower Backpack
(83854, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83854
(83938, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83938
(83920, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83920
(82555, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82555
(88587, 0, 0, 50331648, 1, 0, 0, 0, 0, '123978'), -- 88587 - Mod Scale 95-120%
(83944, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- 83944 - Invisibility and Stealth Detection
(83908, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83908
(83891, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83891 (Gearworks Crab)
(84856, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 84856
(82243, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82243
(87087, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 87087 (Bulbapore)
(81135, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'), -- 81135 - Permanent Feign Death (Stun, Untrackable, Immune)
(81288, 0, 0, 50331648, 1, 0, 0, 0, 0, '123978'), -- 81288 - Mod Scale 95-120%
(82272, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 82272
(81138, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 81138
(88578, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 88578
(89356, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 89356
(85403, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 85403
(88426, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 88426
(81168, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 81168
(61312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61312 (Strand Crab)
(81567, 0, 0, 0, 1, 0, 835, 0, 0, ''), -- 81567 (Repaired Flying Machine)
(85793, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 85793 (Cured Goblin)
(84887, 0, 0, 0, 2, 0, 0, 0, 0, '169654'), -- 84887 - Betsi Boombasket
(85325, 0, 0, 0, 1, 0, 6425, 0, 0, '163894'), -- 85325 - Cosmetic - Mushroom Infection
(82253, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 82253
(88419, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 88419
(81632, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 81632 (Firebomb)
(81566, 0, 0, 0, 1, 0, 835, 0, 0, ''), -- 81566
(81978, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 81978
(82265, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82265
(81443, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 81443 (Krixel Pinchwhistle)
(81184, 0, 0, 0, 1, 0, 6425, 0, 0, '163894'), -- 81184 - Cosmetic - Mushroom Infection
(82182, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 82182
(85647, 0, 0, 0, 1, 0, 5517, 0, 0, '171015'), -- 85647 - Wrecked Hotrod State
(85417, 0, 0, 50331648, 1, 0, 0, 0, 0, '123978'), -- 85417 - Mod Scale 95-120%
(88481, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 88481
(81183, 0, 0, 0, 1, 0, 6425, 0, 0, '163892'), -- 81183 - Cosmetic - Mushroom Infection
(81524, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 81524

UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=3297; -- 3297 (Sen'jin Watcher)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=0 WHERE `entry`=100848; -- 100848 (Darkspear Guardian)
UPDATE `creature_template_addon` SET `bytes1`=8, `bytes2`=1 WHERE `entry`=100852; -- 100852 (Orgrimmar Grunt)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=14376; -- 14376
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=5196; -- 5196 (Gray Riding Wolf)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=93514; -- 93514 (Generic Stalker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=10685; -- 10685
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=5951; -- 5951
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=3123; -- 3123 (Bloodtalon Scythemaw)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=3127; -- 3127 (Venomtail Scorpid)
UPDATE `creature_template_addon` SET `bytes2`=2, `auras`='' WHERE `entry`=91949; -- 91949 (Gnomeregan Tinkerer)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=94209; -- 94209 (Stormwind Knight)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=97503; -- 97503 (Stormwind Knight)
UPDATE `creature_template_addon` SET `auras`='218009' WHERE `entry`=110618; -- 110618 (Anchoring Crystal)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=64121; -- 64121 (Eli)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=97486; -- 97486 (Gilnean Royal Guard)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=93219; -- 93219 (Gilnean Royal Guard)
UPDATE `creature_template_addon` SET `auras`='217980' WHERE `entry`=109494; -- 109494 (Anchor Vehicle)
UPDATE `creature_template_addon` SET `auras`='181308' WHERE `entry`=55091; -- 55091 (General Purpose Bunny JMF (Look 2 - Flying, Infinite AOI))
UPDATE `creature_template_addon` SET `mount`=2328 WHERE `entry`=4311; -- 4311
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=3319; -- 3319
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=37072; -- 37072
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=46512; -- 46512
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=46357; -- 46357
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=62194; -- 62194
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=25080; -- 25080
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=24929; -- 24929
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=44723; -- 44723
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=25081; -- 25081
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=45230; -- 45230
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=46716; -- 46716
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=88704; -- 88704
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=3329; -- 3329
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=47247; -- 47247
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=47248; -- 47248
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=44865; -- 44865
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=256 WHERE `entry`=5188; -- 5188
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=46572; -- 46572
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=62822; -- 62822
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=62821; -- 62821
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=6929; -- 6929
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='303500' WHERE `entry`=149522; -- 149522
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=141119; -- 141119
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=48340; -- 48340

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=12 AND `Entry` IN (86884,88750,100453,3108,6145,160527,160526,160530,160529,160528,105176,105169,105168,105171,105170,90688,111079,111154,91902,105166,105163,111089,92558,111153,111152,105192,105188,105190,105185,105187,105186,105181,105180,105182,105179,111173,105189,105174,111088,111167,105197,105196,111175,111174,105183,105175,105167,111085,111087,111157,111156,105165,105164,114280,105205,105206,105199,105200,111074,92801,114753,114754,114760,114763,114756,114758,114755,114757,114764,114759,114761,114762,114469,91949,94209,97503,92122,110941,113129,105217,90516,90677,105203,113054,113055,90544,113056,113058,113057,102706,113053,102696,90506,113059,102702,91970,105172,97510,92564,101103,112976,91967,102701,94190,94189,94191,112977,110617,110616,97527,97528,100959,93708,97525,110618,101667,90705,101057,45979,90712,109604,114466,113037,113036,113038,97486,97496,114863,93719,112879,114479,92061,108990,93219,93704,109591,113290,112921,97521,92586,109587,91353,72973,90686,109592,109494,91704,90717,90714,90711,90708)) OR (`DifficultyID`=1 AND `Entry` IN (64121,80221,83947,76872,80436,81688,74808,80437,79407,79619,88649,80151,89262,83858,79774,80776,80772,81166,79740,76928,85882,80223,80222,80440,78320,80432,83482,84967,79916,80438,79605,78487,79603,80600,78466,80299,79925,76411,80288,79781,86470));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(86884, 12, 1, 20, 0, 0, 79, 38134),
(88750, 12, 1, 20, 0, 0, 79, 38134),
(100453, 12, 10, 45, 0, 0, 356, 38134),
(3108, 12, 1, 30, 0, 0, 70, 38134),
(6145, 12, 1, 1, 0, 0, 81, 38134),
(160527, 12, 50, 60, 0, 0, 782, 38134),
(160526, 12, 50, 60, 0, 0, 782, 38134),
(160530, 12, 50, 60, 0, 0, 782, 38134),
(160529, 12, 50, 60, 0, 0, 782, 38134),
(160528, 12, 50, 60, 0, 0, 782, 38134),
(105176, 12, 10, 45, 0, 0, 773, 38134),
(105169, 12, 10, 45, 0, 0, 773, 38134),
(105168, 12, 10, 45, 0, 0, 773, 38134),
(105171, 12, 10, 45, 0, 0, 773, 38134),
(105170, 12, 10, 45, 0, 0, 773, 38134),
(90688, 12, 10, 45, 0, 0, 773, 38134),
(111079, 12, 10, 45, 0, 0, 773, 38134),
(111154, 12, 10, 45, 0, 0, 773, 38134),
(91902, 12, 10, 45, 0, 0, 773, 38134),
(105166, 12, 10, 45, 0, 0, 773, 38134),
(105163, 12, 10, 45, 0, 0, 773, 38134),
(111089, 12, 10, 45, 0, 0, 773, 38134),
(92558, 12, 10, 45, 0, 0, 773, 38134),
(111153, 12, 10, 45, 0, 0, 773, 38134),
(111152, 12, 10, 45, 0, 0, 773, 38134),
(105192, 12, 10, 45, 0, 0, 773, 38134),
(105188, 12, 10, 45, 0, 0, 773, 38134),
(105190, 12, 10, 45, 0, 0, 773, 38134),
(105185, 12, 10, 45, 0, 0, 773, 38134),
(105187, 12, 10, 45, 0, 0, 773, 38134),
(105186, 12, 10, 45, 0, 0, 773, 38134),
(105181, 12, 10, 45, 0, 0, 773, 38134),
(105180, 12, 10, 45, 0, 0, 773, 38134),
(105182, 12, 10, 45, 0, 0, 773, 38134),
(105179, 12, 10, 45, 0, 0, 773, 38134),
(111173, 12, 10, 45, 0, 0, 773, 38134),
(105189, 12, 10, 45, 0, 0, 773, 38134),
(105174, 12, 10, 45, 0, 0, 773, 38134),
(111088, 12, 10, 45, 0, 0, 773, 38134),
(111167, 12, 10, 45, 0, 0, 773, 38134),
(105197, 12, 10, 45, 0, 0, 773, 38134),
(105196, 12, 10, 45, 0, 0, 773, 38134),
(111175, 12, 10, 45, 2, 2, 773, 38134),
(111174, 12, 10, 45, 2, 2, 773, 38134),
(105183, 12, 10, 45, 0, 0, 773, 38134),
(105175, 12, 10, 45, 0, 0, 773, 38134),
(105167, 12, 10, 45, 0, 0, 773, 38134),
(111085, 12, 10, 45, 0, 0, 773, 38134),
(111087, 12, 10, 45, 0, 0, 773, 38134),
(111157, 12, 10, 45, 0, 0, 773, 38134),
(111156, 12, 10, 45, 0, 0, 773, 38134),
(105165, 12, 10, 45, 0, 0, 773, 38134),
(105164, 12, 10, 45, 0, 0, 773, 38134),
(114280, 12, 10, 45, 3, 3, 773, 38134),
(105205, 12, 10, 45, 1, 1, 773, 38134),
(105206, 12, 10, 45, 0, 0, 773, 38134),
(105199, 12, 10, 45, 0, 0, 773, 38134),
(105200, 12, 10, 45, 0, 0, 773, 38134),
(111074, 12, 10, 45, 0, 0, 773, 38134),
(92801, 12, 10, 45, 0, 0, 773, 38134),
(114753, 12, 10, 45, 3, 3, 773, 38134),
(114754, 12, 10, 45, 3, 3, 773, 38134),
(114760, 12, 10, 45, 3, 3, 773, 38134),
(114763, 12, 10, 45, 3, 3, 773, 38134),
(114756, 12, 10, 45, 3, 3, 773, 38134),
(114758, 12, 10, 45, 3, 3, 773, 38134),
(114755, 12, 10, 45, 3, 3, 773, 38134),
(114757, 12, 10, 45, 3, 3, 773, 38134),
(114764, 12, 10, 45, 3, 3, 773, 38134),
(114759, 12, 10, 45, 3, 3, 773, 38134),
(114761, 12, 10, 45, 3, 3, 773, 38134),
(114762, 12, 10, 45, 3, 3, 773, 38134),
(114469, 12, 10, 45, 0, 0, 773, 38134),
(91949, 12, 10, 45, 0, 0, 773, 38134),
(94209, 12, 10, 45, 0, 0, 773, 38134),
(97503, 12, 10, 45, 0, 0, 773, 38134),
(92122, 12, 10, 45, 0, 0, 773, 38134),
(110941, 12, 10, 45, 0, 0, 773, 38134),
(113129, 12, 10, 45, 0, 0, 773, 38134),
(105217, 12, 10, 45, 0, 0, 773, 38134),
(90516, 12, 10, 45, 1, 1, 773, 38134),
(90677, 12, 10, 45, 0, 0, 773, 38134),
(105203, 12, 10, 45, 0, 0, 773, 38134),
(113054, 12, 10, 45, 2, 2, 773, 38134),
(113055, 12, 10, 45, 2, 2, 773, 38134),
(90544, 12, 10, 45, 3, 3, 773, 38134),
(113056, 12, 10, 45, 2, 2, 773, 38134),
(113058, 12, 10, 45, 2, 2, 773, 38134),
(113057, 12, 10, 45, 2, 2, 773, 38134),
(102706, 12, 10, 45, 0, 0, 773, 38134),
(113053, 12, 10, 45, 1, 1, 773, 38134),
(102696, 12, 10, 45, 0, 0, 773, 38134),
(90506, 12, 10, 45, 0, 0, 773, 38134),
(113059, 12, 10, 45, 2, 2, 773, 38134),
(102702, 12, 10, 45, 0, 0, 773, 38134),
(91970, 12, 10, 45, 0, 0, 773, 38134),
(105172, 12, 10, 45, 0, 0, 773, 38134),
(97510, 12, 10, 45, 0, 0, 773, 38134),
(92564, 12, 10, 45, 1, 1, 773, 38134),
(101103, 12, 10, 45, 0, 0, 773, 38134),
(112976, 12, 10, 45, 0, 0, 773, 38134),
(91967, 12, 10, 45, 2, 2, 773, 38134),
(102701, 12, 10, 45, 1, 1, 773, 38134),
(94190, 12, 10, 45, 1, 1, 773, 38134),
(94189, 12, 10, 45, 0, 0, 773, 38134),
(94191, 12, 10, 45, 0, 0, 773, 38134),
(112977, 12, 10, 45, 0, 0, 773, 38134),
(110617, 12, 10, 45, 0, 0, 773, 38134),
(110616, 12, 10, 45, 0, 0, 773, 38134),
(97527, 12, 10, 45, 0, 0, 773, 38134),
(97528, 12, 10, 45, 0, 0, 773, 38134),
(100959, 12, 10, 45, 0, 0, 773, 38134),
(93708, 12, 10, 45, 0, 0, 773, 38134),
(97525, 12, 10, 45, 0, 0, 773, 38134),
(110618, 12, 10, 45, 0, 0, 773, 38134),
(101667, 12, 10, 45, 0, 0, 773, 38134),
(90705, 12, 10, 45, 2, 2, 773, 38134),
(101057, 12, 10, 45, 0, 0, 773, 38134),
(64121, 1, 30, 35, 0, 0, 173, 38134),
(80221, 1, 10, 40, 0, 0, 64, 38134),
(83947, 1, 10, 40, 0, 0, 302, 38134),
(76872, 1, 10, 40, 0, 0, 64, 38134),
(80436, 1, 1, 60, 0, 0, 373, 38134),
(81688, 1, 10, 40, 0, 0, 302, 38134),
(74808, 1, 10, 40, 0, 0, 64, 38134),
(80437, 1, 1, 1, 0, 0, 81, 38134),
(79407, 1, 60, 60, 0, 0, 881, 38134),
(79619, 1, 10, 40, 0, 0, 302, 38134),
(88649, 1, 10, 40, 0, 0, 302, 38134),
(80151, 1, 10, 40, 0, 0, 64, 38134),
(89262, 1, 10, 40, 0, 0, 302, 38134),
(83858, 1, 40, 40, 0, 0, 305, 38134),
(79774, 1, 10, 40, 0, 0, 302, 38134),
(80776, 1, 10, 40, 0, 0, 301, 38134),
(80772, 1, 10, 40, 0, 0, 301, 38134),
(81166, 1, 10, 40, 0, 0, 302, 38134),
(79740, 1, 10, 40, 0, 0, 64, 38134),
(76928, 1, 10, 40, 0, 0, 302, 38134),
(85882, 1, 10, 40, 0, 0, 64, 38134),
(80223, 1, 10, 40, 0, 0, 64, 38134),
(80222, 1, 10, 40, 0, 0, 64, 38134),
(80440, 1, 1, 1, 0, 0, 81, 38134),
(78320, 1, 10, 40, 0, 0, 302, 38134),
(80432, 1, 10, 40, 0, 0, 302, 38134),
(83482, 1, 10, 40, 1, 1, 302, 38134),
(84967, 1, 10, 40, 0, 0, 64, 38134),
(79916, 1, 10, 40, 0, 0, 302, 38134),
(80438, 1, 1, 1, 0, 0, 81, 38134),
(79605, 1, 10, 40, 0, 0, 302, 38134),
(78487, 1, 10, 40, 0, 0, 64, 38134),
(79603, 1, 10, 40, 0, 0, 301, 38134),
(80600, 1, 10, 40, 0, 0, 302, 38134),
(78466, 1, 10, 40, 0, 0, 64, 38134),
(80299, 1, 10, 40, 0, 0, 302, 38134),
(79925, 1, 10, 40, 0, 0, 302, 38134),
(76411, 1, 10, 40, 0, 0, 64, 38134),
(80288, 1, 10, 40, 0, 0, 302, 38134),
(79781, 1, 10, 40, 0, 0, 302, 38134),
(86470, 1, 10, 40, 0, 0, 301, 38134),
(45979, 12, 1, 60, 0, 0, 328, 38134),
(90712, 12, 10, 45, 0, 0, 773, 38134),
(109604, 12, 10, 45, 0, 0, 773, 38134),
(114466, 12, 10, 45, 0, 0, 773, 38134),
(113037, 12, 10, 45, 2, 2, 773, 38134),
(113036, 12, 10, 45, 2, 2, 773, 38134),
(113038, 12, 10, 45, 2, 2, 773, 38134),
(97486, 12, 10, 45, 0, 0, 773, 38134),
(97496, 12, 10, 45, 0, 0, 773, 38134),
(114863, 12, 1, 60, 0, 0, 328, 38134),
(93719, 12, 10, 45, 2, 2, 773, 38134),
(112879, 12, 10, 45, 0, 0, 773, 38134),
(114479, 12, 10, 45, 0, 0, 773, 38134),
(92061, 12, 10, 45, 0, 0, 773, 38134),
(108990, 12, 10, 45, 0, 0, 356, 38134),
(93219, 12, 10, 45, 0, 0, 773, 38134),
(93704, 12, 10, 45, 0, 0, 773, 38134),
(109591, 12, 10, 45, 0, 0, 773, 38134),
(113290, 12, 10, 45, 0, 0, 356, 38134),
(112921, 12, 10, 45, 0, 0, 773, 38134),
(97521, 12, 10, 45, 0, 0, 773, 38134),
(92586, 12, 10, 45, 0, 0, 773, 38134),
(109587, 12, 10, 45, 2, 2, 773, 38134),
(91353, 12, 10, 45, 0, 0, 773, 38134),
(72973, 12, 1, 60, 0, 0, 328, 38134),
(90686, 12, 10, 45, 0, 0, 773, 38134),
(109592, 12, 10, 45, 0, 0, 773, 38134),
(109494, 12, 10, 45, 0, 0, 773, 38134),
(91704, 12, 10, 45, 0, 0, 773, 38134),
(90717, 12, 10, 45, 0, 0, 773, 38134),
(90714, 12, 10, 45, 0, 0, 773, 38134),
(90711, 12, 10, 45, 0, 0, 773, 38134),
(90708, 12, 10, 45, 0, 0, 773, 38134);

UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=303, `VerifiedBuild`=38134 WHERE (`Entry`=52382 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=42637 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100720 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100405 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100660 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=112706 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100406 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100442 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113112 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=111935 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=436, `VerifiedBuild`=38134 WHERE (`Entry`=100407 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100467 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMin`=3, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=14720 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=14540 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=11155 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=11154 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100684 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=12147 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=12146 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=12354 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=39380 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=39379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=10685 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=42504 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=5951 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100662 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=61751 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=3123 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=3127 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100679 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=3197 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=62116 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=3198 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=3100 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100682 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100502 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=100663 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=91951 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=90713 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=90709 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=90710 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=112924 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=94276 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=55091 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=90716 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=109341 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=114250 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=101632 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=90525 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113341 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=112923 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113118 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=41621 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113151 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113547 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=40893 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113616 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113615 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=112922 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=436, `VerifiedBuild`=38134 WHERE (`Entry`=114134 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=112920 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=436, `VerifiedBuild`=38134 WHERE (`Entry`=114132 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113959 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113947 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=436, `VerifiedBuild`=38134 WHERE (`Entry`=114133 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113960 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113946 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113945 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113544 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113542 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114106 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113545 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113543 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113546 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113961 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113948 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113949 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113950 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113951 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113955 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113956 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113953 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113957 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=867, `VerifiedBuild`=38134 WHERE (`Entry`=14729 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113952 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113958 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113954 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=108420 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114107 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114108 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113541 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114135 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114136 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113550 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113549 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113551 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113548 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113539 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=97526 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114105 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=113034 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113997 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114114 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113540 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114068 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113374 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113375 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113373 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=4311 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114067 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113377 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113331 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113291 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113376 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113380 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=114066 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=356, `VerifiedBuild`=38134 WHERE (`Entry`=113381 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=55336 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=85798 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=85007 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=80589 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82512 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82558 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82553 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83797 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=881, `VerifiedBuild`=38134 WHERE (`Entry`=82511 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82508 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83930 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=84054 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83786 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82183 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83921 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82516 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83902 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=84093 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82467 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82468 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=48340 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82552 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83744 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83884 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83703 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83854 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83938 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83920 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82555 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=88587 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83944 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83908 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=83891 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=84856 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82243 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=87087 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81135 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=82272 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81138 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=88578 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=89356 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=85403 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=88426 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81168 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=61312 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=85793 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=84887 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=85325 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=82253 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=88359 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=1412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=88419 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81632 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=88988 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81978 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82265 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81443 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81184 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=82182 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=85647 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=85417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=88481 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=6827 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81183 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=81524 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37864;
UPDATE `creature_model_info` SET `BoundingRadius`=0.478749990463256835, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=26770;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=30422;
UPDATE `creature_model_info` SET `BoundingRadius`=0.468749701976776123, `CombatReach`=2.02500009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=72650;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89800;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36789;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64311;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=18153;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=16802;
UPDATE `creature_model_info` SET `BoundingRadius`=1.409832358360290527, `VerifiedBuild`=38134 WHERE `DisplayID`=12241;
UPDATE `creature_model_info` SET `BoundingRadius`=1.409832358360290527, `VerifiedBuild`=38134 WHERE `DisplayID`=12247;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64316;
UPDATE `creature_model_info` SET `BoundingRadius`=1.409832358360290527, `VerifiedBuild`=38134 WHERE `DisplayID`=11641;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36806;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=2107;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=18455;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=18765;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=15730;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=29473;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=7624;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=31255;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37365;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=31262;
UPDATE `creature_model_info` SET `BoundingRadius`=0.751099944114685058, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=1959;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=29482;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2732;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=3000;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=30441;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4190;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4192;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=29349;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4193;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=46940;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=30787;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36793;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=16800;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4191;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33829;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=17538;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=60400;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36857;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=60030;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=6468;
UPDATE `creature_model_info` SET `BoundingRadius`=1.614788532257080078, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=4878;
UPDATE `creature_model_info` SET `BoundingRadius`=2.559763431549072265, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=91243;
UPDATE `creature_model_info` SET `BoundingRadius`=0.392066627740859985, `CombatReach`=8, `VerifiedBuild`=38134 WHERE `DisplayID`=91373;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93309;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92324;
UPDATE `creature_model_info` SET `BoundingRadius`=0.425779640674591064, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=92325;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67643;
UPDATE `creature_model_info` SET `BoundingRadius`=10.07576179504394531, `CombatReach`=16.20000076293945312, `VerifiedBuild`=38134 WHERE `DisplayID`=74998;
UPDATE `creature_model_info` SET `BoundingRadius`=10.07532501220703125, `CombatReach`=9, `VerifiedBuild`=38134 WHERE `DisplayID`=68981;
UPDATE `creature_model_info` SET `BoundingRadius`=7.292841911315917968, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=68984;
UPDATE `creature_model_info` SET `BoundingRadius`=7.292841911315917968, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=68983;
UPDATE `creature_model_info` SET `BoundingRadius`=10.07575798034667968, `CombatReach`=16.20000076293945312, `VerifiedBuild`=38134 WHERE `DisplayID`=73473;
UPDATE `creature_model_info` SET `BoundingRadius`=6.716883182525634765, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=67759;
UPDATE `creature_model_info` SET `BoundingRadius`=10.2908477783203125, `CombatReach`=8.800000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=72708;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66677;
UPDATE `creature_model_info` SET `BoundingRadius`=10.40445327758789062, `VerifiedBuild`=38134 WHERE `DisplayID`=71735;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58049;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71715;
UPDATE `creature_model_info` SET `BoundingRadius`=4, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=71733;
UPDATE `creature_model_info` SET `BoundingRadius`=4, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=71732;
UPDATE `creature_model_info` SET `BoundingRadius`=2.349424123764038085, `VerifiedBuild`=38134 WHERE `DisplayID`=71718;
UPDATE `creature_model_info` SET `BoundingRadius`=1.92712414264678955, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=71717;
UPDATE `creature_model_info` SET `BoundingRadius`=3.669828414916992187, `VerifiedBuild`=38134 WHERE `DisplayID`=71716;
UPDATE `creature_model_info` SET `BoundingRadius`=4.207308769226074218, `VerifiedBuild`=38134 WHERE `DisplayID`=62560;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66411;
UPDATE `creature_model_info` SET `BoundingRadius`=2.524385452270507812, `VerifiedBuild`=38134 WHERE `DisplayID`=62559;
UPDATE `creature_model_info` SET `BoundingRadius`=1.773619890213012695, `VerifiedBuild`=38134 WHERE `DisplayID`=68987;
UPDATE `creature_model_info` SET `BoundingRadius`=1.773619890213012695, `VerifiedBuild`=38134 WHERE `DisplayID`=68986;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63484;
UPDATE `creature_model_info` SET `BoundingRadius`=4.099837303161621093, `VerifiedBuild`=38134 WHERE `DisplayID`=29615;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71030;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=20915;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=68828;
UPDATE `creature_model_info` SET `BoundingRadius`=6.346993446350097656, `VerifiedBuild`=38134 WHERE `DisplayID`=69438;
UPDATE `creature_model_info` SET `BoundingRadius`=2.265863418579101562, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=71032;
UPDATE `creature_model_info` SET `BoundingRadius`=5.828500747680664062, `CombatReach`=12, `VerifiedBuild`=38134 WHERE `DisplayID`=71741;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71662;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66219;
UPDATE `creature_model_info` SET `BoundingRadius`=2.569311380386352539, `CombatReach`=8, `VerifiedBuild`=38134 WHERE `DisplayID`=65948;
UPDATE `creature_model_info` SET `BoundingRadius`=1.54624795913696289, `VerifiedBuild`=38134 WHERE `DisplayID`=62586;
UPDATE `creature_model_info` SET `BoundingRadius`=9.586133956909179687, `CombatReach`=12, `VerifiedBuild`=38134 WHERE `DisplayID`=73163;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65203;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73186;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73107;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73108;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73450;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73445;
UPDATE `creature_model_info` SET `BoundingRadius`=5.138622760772705078, `VerifiedBuild`=38134 WHERE `DisplayID`=73441;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73447;
UPDATE `creature_model_info` SET `BoundingRadius`=5.138622760772705078, `VerifiedBuild`=38134 WHERE `DisplayID`=73442;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73448;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73446;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73449;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73071;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73443;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73444;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73278;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73279;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73277;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=72227;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73090;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73089;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=72229;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73069;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73072;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73070;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65514;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65157;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71701;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=62749;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72943;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=67757;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=65939;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63676;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64006;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66118;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=9129;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67321;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63786;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73166;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=62716;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67761;
UPDATE `creature_model_info` SET `BoundingRadius`=6.62443399429321289, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=71253;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=14518;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=54243;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=16239;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=16236;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67705;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63784;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=16240;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=16237;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67173;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=73068;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=73065;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=73066;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73179;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73176;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73180;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67264;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73058;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73062;
UPDATE `creature_model_info` SET `BoundingRadius`=0.440539717674255371, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=73275;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73083;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73282;
UPDATE `creature_model_info` SET `BoundingRadius`=0.440539717674255371, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=73273;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=63489;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66895;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73060;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73177;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72780;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72809;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=55586;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53501;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=23037;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53057;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2176;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=59993;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=7129;
UPDATE `creature_model_info` SET `BoundingRadius`=0.283200025558471679, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=49286;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55531;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=19113;
UPDATE `creature_model_info` SET `BoundingRadius`=0.660000026226043701, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=64389;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=18941;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=52012;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56542;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59254;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59175;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53538;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56541;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59193;
UPDATE `creature_model_info` SET `BoundingRadius`=0.344699978828430175, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=55589;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43247;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=23481;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53327;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55740;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57734;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58595;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=1395;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=28289;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55581;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=55735;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53001;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56544;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59255;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53609;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59253;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55579;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59624;
UPDATE `creature_model_info` SET `BoundingRadius`=0.440539717674255371, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=73274;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73188;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73088;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73281;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73061;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73175;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70533;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73283;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66934;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73272;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73064;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64753;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65980;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66898;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66897;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=66933;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73081;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=18526;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27317;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73187;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73280;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27913;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63101;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73085;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=14780;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73059;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=66896;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67324;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73084;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=5047;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67028;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=73181;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73183;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73189;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63921;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70626;
UPDATE `creature_model_info` SET `BoundingRadius`=0.609152197837829589, `VerifiedBuild`=38134 WHERE `DisplayID`=73184;
UPDATE `creature_model_info` SET `BoundingRadius`=1.814528107643127441, `CombatReach`=4.967999935150146484, `VerifiedBuild`=38134 WHERE `DisplayID`=66086;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27314;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63920;
UPDATE `creature_model_info` SET `BoundingRadius`=1.1498185396194458, `CombatReach`=3.000000238418579101, `VerifiedBuild`=38134 WHERE `DisplayID`=80352;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67686;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67685;
UPDATE `creature_model_info` SET `BoundingRadius`=0.369329810142517089, `VerifiedBuild`=38134 WHERE `DisplayID`=7006;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65304;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67684;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27315;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67687;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27313;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=15701;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=72448;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32529;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=1976;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27895;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=46131;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=48768;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27101;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72100;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73043;
UPDATE `creature_model_info` SET `BoundingRadius`=0.767800033092498779, `CombatReach`=3.300000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=72099;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=60073;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=60549;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72097;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=61346;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72779;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=57430;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=60486;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58456;
UPDATE `creature_model_info` SET `BoundingRadius`=0.421299993991851806, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=61369;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56527;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=61353;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=60406;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=60465;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58680;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72800;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58687;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=60558;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=60518;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=61519;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58259;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59972;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=61508;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72801;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=14756;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=60036;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=60449;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=61503;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=72793;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=72786;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=61500;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=72795;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=72790;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58488;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=57238;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73052;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=46130;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73048;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73047;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58265;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73053;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58462;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73051;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58677;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58369;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73049;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56716;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73054;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56567;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73050;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=72783;
UPDATE `creature_model_info` SET `BoundingRadius`=7.434527873992919921, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=73028;
UPDATE `creature_model_info` SET `BoundingRadius`=0.943689465522766113, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=73121;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72797;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72784;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72805;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=72808;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=72787;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72804;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45692;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44315;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=72789;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=72792;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72782;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=72803;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=72791;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=72781;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72765;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=34208;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=34207;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72799;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72798;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72778;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=29310;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73128;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72796;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72802;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=72806;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90254;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=99426;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=2141;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=9392;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=8572;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=38380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.442471057176589965, `VerifiedBuild`=38134 WHERE `DisplayID`=59131;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=58614;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=54715;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=25587;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57078;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57067;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57957;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57043;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57042;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58035;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58105;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57084;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56878;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58034;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57044;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57083;
UPDATE `creature_model_info` SET `BoundingRadius`=0.138684809207916259, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=5448;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58120;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57905;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36114;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36115;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57064;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57929;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58041;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57068;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58011;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57904;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57066;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58223;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57070;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58026;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58044;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57069;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58829;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58043;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58042;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=57065;
UPDATE `creature_model_info` SET `BoundingRadius`=4.581903457641601562, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=52740;
UPDATE `creature_model_info` SET `BoundingRadius`=1.708577871322631835, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=59508;
UPDATE `creature_model_info` SET `BoundingRadius`=2.990011215209960937, `CombatReach`=5.25, `VerifiedBuild`=38134 WHERE `DisplayID`=59512;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=56909;
UPDATE `creature_model_info` SET `BoundingRadius`=0.801750004291534423, `CombatReach`=0.25, `VerifiedBuild`=38134 WHERE `DisplayID`=56338;
UPDATE `creature_model_info` SET `BoundingRadius`=0.464532017707824707, `CombatReach`=0.300000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=56920;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57560;
UPDATE `creature_model_info` SET `BoundingRadius`=1.720709085464477539, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=55976;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=38377;
UPDATE `creature_model_info` SET `BoundingRadius`=1.146849393844604492, `CombatReach`=0.559183716773986816, `VerifiedBuild`=38134 WHERE `DisplayID`=56522;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58746;
UPDATE `creature_model_info` SET `BoundingRadius`=2.050934791564941406, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=57451;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58790;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58751;
UPDATE `creature_model_info` SET `BoundingRadius`=0.367200016975402832, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=58549;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59066;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56534;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58789;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59067;
UPDATE `creature_model_info` SET `BoundingRadius`=0.190674349665641784, `CombatReach`=0.100000001490116119, `VerifiedBuild`=38134 WHERE `DisplayID`=59877;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56270;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=60892;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=56477;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=60864;
UPDATE `creature_model_info` SET `BoundingRadius`=5.458125114440917968, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=56437;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56213;
UPDATE `creature_model_info` SET `BoundingRadius`=2.243150711059570312, `CombatReach`=2.625, `VerifiedBuild`=38134 WHERE `DisplayID`=60091;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56410;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58750;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36112;
UPDATE `creature_model_info` SET `BoundingRadius`=3.004200458526611328, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=45473;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58839;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58838;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=33006;


UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=386;


UPDATE `trainer_spell` SET `MoneyCost`=950, `VerifiedBuild`=38134 WHERE (`TrainerId`=386 AND `SpellId`=33389);
UPDATE `trainer_spell` SET `MoneyCost`=47500000, `ReqLevel`=40 WHERE (`TrainerId`=386 AND `SpellId`=90266);
UPDATE `trainer_spell` SET `MoneyCost`=475000, `VerifiedBuild`=38134 WHERE (`TrainerId`=386 AND `SpellId`=33392);
UPDATE `trainer_spell` SET `MoneyCost`=2375000, `VerifiedBuild`=38134 WHERE (`TrainerId`=386 AND `SpellId`=34092);

DELETE FROM `npc_vendor` WHERE (`entry`=76872 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=76872 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=76872 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=76872 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=76872 AND `item`=183953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=76872 AND `item`=183954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=76872 AND `item`=183955 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80151 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80151 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80151 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80151 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80151 AND `item`=183953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80151 AND `item`=183954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80151 AND `item`=183955 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(76872, 24, 183950, 0, 0, 1, 0, 0, 38134), -- Distilled Death Extract
(76872, 23, 180733, 0, 0, 1, 0, 0, 38134), -- Luminous Flux
(76872, 22, 183951, 0, 0, 1, 0, 0, 38134), -- Immortal Shard
(76872, 21, 183952, 0, 0, 1, 0, 0, 38134), -- Machinist's Oil
(76872, 20, 183953, 0, 0, 1, 0, 0, 38134), -- Sealing Wax
(76872, 19, 183954, 0, 0, 1, 0, 0, 38134), -- Malleable Wire
(76872, 18, 183955, 0, 0, 1, 0, 0, 38134), -- Curing Salt
(80151, 28, 183950, 0, 0, 1, 0, 0, 38134), -- Distilled Death Extract
(80151, 27, 180733, 0, 0, 1, 0, 0, 38134), -- Luminous Flux
(80151, 26, 183951, 0, 0, 1, 0, 0, 38134), -- Immortal Shard
(80151, 25, 183952, 0, 0, 1, 0, 0, 38134), -- Machinist's Oil
(80151, 24, 183953, 0, 0, 1, 0, 0, 38134), -- Sealing Wax
(80151, 23, 183954, 0, 0, 1, 0, 0, 38134), -- Malleable Wire
(80151, 22, 183955, 0, 0, 1, 0, 0, 38134); -- Curing Salt

UPDATE `npc_vendor` SET `slot`=46, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=81923 AND `ExtendedCost`=0 AND `type`=1); -- Cobo Cola
UPDATE `npc_vendor` SET `slot`=45, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=81924 AND `ExtendedCost`=0 AND `type`=1); -- Carbonated Water
UPDATE `npc_vendor` SET `slot`=44, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=58257 AND `ExtendedCost`=0 AND `type`=1); -- Highland Spring Water
UPDATE `npc_vendor` SET `slot`=43, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=58256 AND `ExtendedCost`=0 AND `type`=1); -- Sparkling Oasis Water
UPDATE `npc_vendor` SET `slot`=42, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=33445 AND `ExtendedCost`=0 AND `type`=1); -- Honeymint Tea
UPDATE `npc_vendor` SET `slot`=41, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=33444 AND `ExtendedCost`=0 AND `type`=1); -- Pungent Seal Whey
UPDATE `npc_vendor` SET `slot`=40, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=58274 AND `ExtendedCost`=0 AND `type`=1); -- Fresh Water
UPDATE `npc_vendor` SET `slot`=39, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=38, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=37, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=36, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=35, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=81918 AND `ExtendedCost`=0 AND `type`=1); -- Pickled Pig's Snout
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=81917 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Stew
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=58269 AND `ExtendedCost`=0 AND `type`=1); -- Massive Turkey Leg
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=58268 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Beef
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=35953 AND `ExtendedCost`=0 AND `type`=1); -- Mead Basted Caribou
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=33454 AND `ExtendedCost`=0 AND `type`=1); -- Salted Venison
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=81920 AND `ExtendedCost`=0 AND `type`=1); -- Plump Fig
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=81919 AND `ExtendedCost`=0 AND `type`=1); -- Red Raspberry
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=58265 AND `ExtendedCost`=0 AND `type`=1); -- Highland Pomegranate
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=58264 AND `ExtendedCost`=0 AND `type`=1); -- Sour Green Apple
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=35948 AND `ExtendedCost`=0 AND `type`=1); -- Savory Snowplum
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=35949 AND `ExtendedCost`=0 AND `type`=1); -- Tundra Berries
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1); -- Tel'Abim Banana
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=122560 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Whiptail Fillet
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=122555 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Sleeper Sushi
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=122559 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Salty Squid Roll
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=122558 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Pickled Eel
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=122557 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Jumbo Sea Dog
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=76928 AND `item`=122556 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Buttered Sturgeon
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=117445 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Hide Satchel
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Tinker's Kit
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=115351 AND `ExtendedCost`=0 AND `type`=1); -- "Rylak Claws"
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=76872 AND `item`=117452 AND `ExtendedCost`=0 AND `type`=1); -- Gorgrond Mineral Water
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=117445 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Hide Satchel
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Tinker's Kit
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=115355 AND `ExtendedCost`=0 AND `type`=1); -- Marbled Clefthoof Steak
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=115354 AND `ExtendedCost`=0 AND `type`=1); -- Sliced Zangar Buttons
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=115353 AND `ExtendedCost`=0 AND `type`=1); -- Tanaan Sweetmelon
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=115352 AND `ExtendedCost`=0 AND `type`=1); -- Telmor-Aruuna Hard Cheese
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=115351 AND `ExtendedCost`=0 AND `type`=1); -- "Rylak Claws"
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=80151 AND `item`=117452 AND `ExtendedCost`=0 AND `type`=1); -- Gorgrond Mineral Water

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (100405,100660,112706,100442,111935,100407,100453,160526,160529,160528,111154,105166,105163,92558,105192,105188,105190,105181,105182,105179,105174,111088,111167,105196,105183,105175,111085,111087,111156,105165,105164,114280,105205,105206,105200,114753,114754,114760,114763,114756,114758,114755,114764,114761,114762,114469,92122,110941,90516,90677,105203,113058,113057,113059,102702,91970,97510,92564,102701,110617,110616,97527,97528,93708,97525,90705,80221,83947,81688,79619,88649,79774,81166,76928,85882,80223,80222,83482,84967,78466,90712,109604,114466,113037,113036,113038,97496,93719,112879,114479,93704,109591,112921,97521,92586,109587,91353,109592,90714,90711,90708,91951,90713,90709,90710,113151,113616,112920,113959,113947,113946,113945,113544,113374,114106,113543,113331,113373,113546,113961,113381,113948,113949,113950,113375,113951,113955,113956,113953,113957,113377,113952,113958,113954,113376,113380,114107,114108,113541,113551,113539,97526,113034,114067,114066,84054,81978,81443));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(100405, 1, 58367, 0, 0, 0, 0, 0, 0, 0, 0), -- Baine Bloodhoof
(100660, 1, 168606, 0, 0, 0, 0, 0, 0, 0, 0), -- Lor'themar Theron
(112706, 1, 35781, 0, 0, 0, 0, 0, 0, 0, 0), -- Aethas Sunreaver
(100442, 1, 14085, 0, 0, 0, 0, 0, 14118, 0, 0), -- Vol'jin
(111935, 1, 5289, 0, 0, 0, 0, 0, 2507, 0, 0), -- Orgrimmar Grunt
(100407, 1, 0, 0, 0, 0, 0, 0, 42775, 0, 0), -- Lady Sylvanas Windrunner
(100453, 1, 10612, 0, 0, 0, 0, 0, 0, 0, 0), -- Eitrigg
(160526, 1, 169079, 0, 0, 169079, 0, 0, 0, 0, 0), -- Neri Sharpfin
(160529, 1, 169020, 0, 0, 0, 0, 0, 0, 0, 0), -- Vim Brineheart
(160528, 1, 169080, 0, 0, 0, 0, 0, 0, 0, 0), -- Poen Gillbrack
(111154, 1, 28365, 0, 0, 0, 0, 0, 0, 0, 0), -- Malgalor
(105166, 1, 127648, 0, 0, 0, 0, 0, 0, 0, 0), -- Gorgonnash
(105163, 1, 127648, 0, 0, 0, 0, 0, 0, 0, 0), -- Destromath
(92558, 1, 85737, 0, 0, 0, 0, 0, 0, 0, 0), -- Arkethrax
(105192, 1, 128832, 0, 0, 128831, 0, 0, 0, 0, 0), -- Caria Felsoul
(105188, 1, 132101, 0, 0, 0, 0, 0, 0, 0, 0), -- Cordana Felsong
(105190, 1, 127829, 0, 0, 127830, 0, 0, 0, 0, 0), -- Varedis Felsoul
(105181, 1, 31609, 0, 0, 31609, 0, 0, 0, 0, 0), -- Lady Sacrolash
(105182, 1, 102151, 0, 0, 0, 0, 0, 0, 0, 0), -- Gravax the Desecrator
(105179, 1, 43619, 0, 0, 0, 0, 0, 0, 0, 0), -- Lord Jaraxxus
(105174, 1, 128519, 0, 0, 0, 0, 0, 0, 0, 0), -- Smashspite the Hateful
(111088, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Lord Perdition
(111167, 1, 124524, 0, 0, 0, 0, 0, 0, 0, 0), -- Lochaber
(105196, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Brogozog
(105183, 1, 129275, 0, 0, 0, 0, 0, 0, 0, 0), -- Lord Kra'vos
(105175, 1, 105954, 0, 0, 0, 0, 0, 0, 0, 0), -- Blerg
(111085, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Geth'xun
(111087, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Hakkar the Houndmaster
(111156, 1, 124524, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel Lord Dakuur
(105165, 1, 138755, 0, 0, 0, 0, 0, 0, 0, 0), -- Felgard Legionnaire
(105164, 1, 138754, 0, 0, 0, 0, 0, 0, 0, 0), -- Felgard Legionnaire
(114280, 1, 124448, 0, 0, 128200, 0, 0, 0, 0, 0), -- Vizuul the Twisted
(105205, 1, 140159, 0, 0, 0, 0, 0, 0, 0, 0), -- Mo'arg Spinebreaker
(105206, 1, 132920, 0, 0, 132920, 0, 0, 0, 0, 0), -- Wrathguard Dreadblade
(105200, 1, 138753, 0, 0, 0, 0, 0, 0, 0, 0), -- Felguard Invader
(114753, 1, 28365, 0, 0, 0, 0, 0, 0, 0, 0), -- Gorgoloth
(114754, 1, 28365, 0, 0, 0, 0, 0, 0, 0, 0), -- Mazgoroth
(114760, 1, 31609, 0, 0, 0, 0, 0, 0, 0, 0), -- Harbinger Faraleth
(114763, 1, 100540, 0, 0, 0, 0, 0, 0, 0, 0), -- Darkmagus Drazzok
(114756, 1, 128279, 0, 0, 0, 0, 0, 0, 0, 0), -- Dread Knight Zak'gal
(114758, 1, 30723, 0, 0, 0, 0, 0, 0, 0, 0), -- Flamecaller Vezrah
(114755, 1, 128279, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel Lord Kaz'ral
(114764, 1, 100540, 0, 0, 0, 0, 0, 0, 0, 0), -- Darkmagus Falo'reth
(114761, 1, 128199, 0, 0, 0, 0, 0, 0, 0, 0), -- Arch Magus Velysra
(114762, 1, 128199, 0, 0, 0, 0, 0, 0, 0, 0), -- Arch Magus Zyrel
(114469, 1, 94667, 0, 0, 110156, 0, 0, 0, 0, 0), -- Exodar Vindicator
(92122, 1, 0, 0, 0, 0, 0, 0, 59367, 0, 0), -- Gnomeregan Tinkerer
(110941, 1, 40595, 0, 0, 40596, 0, 0, 0, 0, 0), -- Desiccated Crusader
(90516, 1, 140159, 0, 0, 0, 0, 0, 0, 0, 0), -- Mo'arg Painbringer
(90677, 1, 132920, 0, 0, 132920, 0, 0, 0, 0, 0), -- Wrathguard Dreadblade
(105203, 1, 138753, 0, 0, 0, 0, 0, 0, 0, 0), -- Felguard Invader
(113058, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel Lord Volak
(113057, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel Lord Durkan
(113059, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel Lord Garzan
(102702, 1, 132920, 0, 0, 132920, 0, 0, 0, 0, 0), -- Wrathguard Dreadblade
(91970, 1, 138753, 0, 0, 0, 0, 0, 0, 0, 0), -- Felguard Invader
(97510, 1, 100540, 0, 0, 72255, 0, 0, 0, 0, 0), -- Soulbound Destructor
(92564, 1, 128519, 0, 0, 0, 0, 0, 0, 0, 0), -- Mo'arg Painbringer
(102701, 1, 128521, 0, 0, 0, 0, 0, 0, 0, 0), -- Mo'arg Painbringer
(110617, 1, 113838, 0, 0, 0, 0, 0, 0, 0, 0), -- Shadowsworn Harbinger
(110616, 1, 97238, 0, 0, 0, 0, 0, 0, 0, 0), -- Dark Worshipper
(97527, 1, 2176, 0, 0, 0, 0, 0, 0, 0, 0), -- Argent Lightbringer
(97528, 1, 2176, 0, 0, 0, 0, 0, 0, 0, 0), -- Argent Lightbringer
(93708, 1, 12754, 0, 0, 0, 0, 0, 0, 0, 0), -- Thunder Bluff Brave
(97525, 1, 12754, 0, 0, 0, 0, 0, 0, 0, 0), -- Thunder Bluff Brave
(90705, 1, 132981, 0, 0, 0, 0, 0, 0, 0, 0), -- Dread Commander Arganoth
(80221, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(83947, 1, 31824, 0, 0, 31824, 0, 0, 0, 0, 0), -- Kimzee Pinchwhistle
(81688, 1, 2901, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(79619, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(88649, 1, 10612, 0, 0, 10612, 0, 0, 0, 0, 0), -- Draka
(79774, 1, 108921, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(81166, 1, 10612, 0, 0, 10612, 0, 0, 0, 0, 0), -- -Unknown-
(76928, 1, 0, 0, 0, 18425, 0, 0, 0, 0, 0), -- Kraank
(85882, 1, 0, 0, 0, 0, 0, 0, 71077, 0, 0), -- -Unknown-
(80223, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- Lady Sena
(80222, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- Mr. Pleeb
(83482, 1, 0, 0, 0, 107321, 0, 0, 0, 0, 0), -- -Unknown-
(84967, 1, 28768, 0, 0, 28768, 0, 0, 0, 0, 0), -- -Unknown-
(78466, 1, 4994, 0, 0, 13855, 0, 0, 12523, 0, 0), -- Gazlowe
(90712, 1, 140546, 0, 0, 0, 0, 0, 0, 0, 0), -- Earthen Ring Shaman
(109604, 1, 138755, 0, 0, 0, 0, 0, 0, 0, 0), -- Felguard Legionnaire
(114466, 1, 5598, 0, 0, 5598, 0, 0, 0, 0, 0), -- Darnassus Sentinel
(113037, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel Lord Darakk
(113036, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel Lord Razzar
(113038, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel Lord Kurrz
(97496, 1, 45726, 0, 0, 45727, 0, 0, 0, 0, 0), -- Kirin Tor Battle-Mage
(93719, 1, 140775, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel Commander Azgalor
(112879, 1, 73008, 0, 0, 0, 0, 0, 0, 0, 0), -- Horde Priest
(114479, 1, 53098, 0, 0, 0, 0, 0, 0, 0, 0), -- Silvermoon Blood Knight
(93704, 1, 13631, 0, 0, 0, 0, 0, 0, 0, 0), -- Darkspear Headhunter
(109591, 1, 138754, 0, 0, 0, 0, 0, 0, 0, 0), -- Felguard Legionnaire
(112921, 1, 0, 0, 0, 0, 0, 0, 110315, 0, 0), -- Bilgewater Blastmaster
(97521, 1, 140546, 0, 0, 0, 0, 0, 0, 0, 0), -- Earthen Ring Shaman
(92586, 1, 0, 0, 0, 0, 0, 0, 110314, 0, 0), -- Ironforge Cannoneer
(109587, 1, 139022, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel Lord Zardak
(91353, 1, 45726, 0, 0, 45727, 0, 0, 0, 0, 0), -- Kirin Tor Battle-Mage
(109592, 1, 138756, 0, 0, 0, 0, 0, 0, 0, 0), -- Felguard Legionnaire
(90714, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0), -- Lady Jaina Proudmoore
(90711, 1, 140777, 0, 0, 0, 0, 0, 0, 0, 0), -- Thrall
(90708, 1, 140776, 0, 0, 0, 0, 0, 14118, 0, 0), -- Vol'jin
(91951, 1, 13262, 0, 0, 0, 0, 0, 0, 0, 0), -- Highlord Tirion Fordring
(90713, 1, 45899, 0, 0, 0, 0, 0, 0, 0, 0), -- King Varian Wrynn
(90709, 1, 2179, 0, 0, 0, 0, 0, 42775, 0, 0), -- Lady Sylvanas Windrunner
(90710, 1, 58367, 0, 0, 0, 0, 0, 0, 0, 0), -- Baine Bloodhoof
(113151, 1, 1904, 0, 0, 0, 0, 0, 0, 0, 0), -- Fo'rum the Postmaker
(113616, 1, 5284, 0, 0, 0, 0, 0, 0, 0, 0), -- Garyl
(112920, 1, 0, 0, 0, 0, 0, 0, 97227, 0, 0), -- Dark Ranger
(113959, 1, 62475, 0, 0, 67124, 0, 0, 0, 0, 0), -- Shappa
(113947, 1, 21492, 0, 0, 0, 0, 0, 0, 0, 0), -- Maska
(113946, 1, 50047, 0, 0, 59444, 0, 0, 0, 0, 0), -- Karn Steelhoof
(113945, 1, 40281, 0, 0, 49437, 0, 0, 0, 0, 0), -- Omril Keenedge
(113544, 1, 67098, 0, 0, 0, 0, 0, 0, 0, 0), -- Neejala
(113374, 1, 136591, 0, 0, 0, 0, 0, 0, 0, 0), -- Horde Recruit
(114106, 1, 108940, 0, 0, 0, 0, 0, 0, 0, 0), -- Sergeant Grimjaw
(113543, 1, 24352, 0, 0, 0, 0, 0, 0, 0, 0), -- Annix Strifesprocket
(113331, 1, 136591, 0, 0, 0, 0, 0, 0, 0, 0), -- Horde Recruit
(113373, 1, 136591, 0, 0, 0, 0, 0, 0, 0, 0), -- Horde Recruit
(113546, 1, 11932, 0, 0, 0, 0, 0, 0, 0, 0), -- Yaalo
(113961, 1, 42274, 0, 0, 42277, 0, 0, 0, 0, 0), -- Pinkee Rizzo
(113381, 1, 136591, 0, 0, 0, 0, 0, 0, 0, 0), -- Horde Recruit
(113948, 1, 50428, 0, 0, 40350, 0, 0, 0, 0, 0), -- Arienne Black
(113949, 1, 5191, 0, 0, 5191, 0, 0, 0, 0, 0), -- Rizza Brassrokkit
(113950, 1, 34996, 0, 0, 34988, 0, 0, 0, 0, 0), -- Lonan
(113375, 1, 136591, 0, 0, 0, 0, 0, 0, 0, 0), -- Horde Recruit
(113951, 1, 63680, 0, 0, 65052, 0, 0, 0, 0, 0), -- Sahale
(113955, 1, 47509, 0, 0, 39716, 0, 0, 0, 0, 0), -- Utona Wolfeye
(113956, 1, 22799, 0, 0, 0, 0, 0, 0, 0, 0), -- Taela Shatterborne
(113953, 1, 55362, 0, 0, 9661, 0, 0, 0, 0, 0), -- Faala
(113957, 1, 50429, 0, 0, 0, 0, 0, 0, 0, 0), -- Ja'kala
(113377, 1, 136591, 0, 0, 0, 0, 0, 0, 0, 0), -- Horde Recruit
(113952, 1, 42277, 0, 0, 19335, 0, 0, 0, 0, 0), -- Aila Dourblade
(113958, 1, 45256, 0, 0, 0, 0, 0, 0, 0, 0), -- Handel Shadereaver
(113954, 1, 38618, 0, 0, 0, 0, 0, 0, 0, 0), -- Argonis Solheart
(113376, 1, 136591, 0, 0, 0, 0, 0, 0, 0, 0), -- Horde Recruit
(113380, 1, 136591, 0, 0, 0, 0, 0, 0, 0, 0), -- Horde Recruit
(114107, 1, 41824, 0, 0, 0, 0, 0, 0, 0, 0), -- Lan'veros Furybrand
(114108, 1, 41824, 0, 0, 0, 0, 0, 0, 0, 0), -- Merhean Sunfall
(113541, 1, 18048, 0, 0, 25073, 0, 0, 0, 0, 0), -- Seleria Dawncaller
(113551, 1, 50429, 0, 0, 0, 0, 0, 0, 0, 0), -- Ja'kala
(113539, 1, 45123, 0, 0, 0, 0, 0, 0, 0, 0), -- Orgek Ironhand
(97526, 1, 5286, 0, 0, 5286, 0, 0, 0, 0, 0), -- Deathguard Elite
(113034, 1, 13631, 0, 0, 0, 0, 0, 0, 0, 0), -- Darkspear Headhunter
(114067, 1, 13631, 0, 0, 0, 0, 0, 0, 0, 0), -- Darkspear Bat Rider
(114066, 1, 5289, 0, 0, 0, 0, 0, 0, 0, 0), -- Orgrimmar Wind Rider
(84054, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(81978, 1, 31824, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(81443, 1, 31824, 0, 0, 0, 0, 0, 42486, 0, 0); -- Krixel Pinchwhistle


DELETE FROM `gossip_menu` WHERE (`MenuId`=19116 AND `TextId`=28026) OR (`MenuId`=20306 AND `TextId`=30383) OR (`MenuId`=16277 AND `TextId`=23538) OR (`MenuId`=16296 AND `TextId`=23580) OR (`MenuId`=16801 AND `TextId`=24430) OR (`MenuId`=17052 AND `TextId`=24994) OR (`MenuId`=16474 AND `TextId`=23891) OR (`MenuId`=16462 AND `TextId`=23875) OR (`MenuId`=16450 AND `TextId`=23846);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(19116, 28026, 38134), -- 100636 (High Overlord Saurfang)
(20306, 30383, 38134), -- 113118 (Captain Russo)
(16277, 23538, 38134), -- 76928 (Kraank)
(16296, 23580, 38134), -- 76872
(16801, 24430, 38134), -- 78487 (Rokhan)
(17052, 24994, 38134), -- 79619
(16474, 23891, 38134), -- 80223 (Lady Sena)
(16462, 23875, 38134), -- 80151
(16450, 23846, 38134); -- 79740

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16797 AND `TextId`=24424); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16593 AND `TextId`=7778); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16593 AND `TextId`=7778); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=18757 AND `TextId`=27278); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=19861 AND `TextId`=29496); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16596 AND `TextId`=24099); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16596 AND `TextId`=24099); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16596 AND `TextId`=24099); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16596 AND `TextId`=24099); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16993 AND `TextId`=24737); -- 0

DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (19116,20306,16277,16296,17052,16462));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(19116, 0, 0, 'Take me inside Grommash Hold.', 103164, 38134),
(20306, 0, 0, 'I am ready to face the Legion.', 114581, 38134),
(16277, 0, 1, 'May I see your wares?', 12790, 38134),
(16296, 0, 1, 'I would like to buy from you.', 2583, 38134), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(17052, 0, 1, 'I would like to buy from you.', 2583, 38134), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(16462, 0, 1, 'Let me browse your goods.', 2823, 38134); -- OptionBroadcastTextID: 2823 - 7509 - 8097

UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=18757 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=19861 AND `OptionIndex`=0);




UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=100873; -- Allari the Souleater
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15 WHERE `entry`=100865; -- Sen'jin Spirit Drummer
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15 WHERE `entry`=100848; -- Darkspear Guardian
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15 WHERE `entry`=100856; -- Ceremonial Watcher
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15 WHERE `entry`=100867; -- Lor'themar Theron
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=100866; -- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=52382; -- Ziradormi
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0 WHERE `entry`=42637; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=102, `maxlevel`=102, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=100720; -- Trade Prince Gallywix
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15, `faction`=2773, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=100405; -- Baine Bloodhoof
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=100660; -- Lor'themar Theron
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2361, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112706; -- Aethas Sunreaver
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1734, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=100406; -- Ji Firepaw
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15, `faction`=2714, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=100442; -- Vol'jin
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `VehicleId`=4951 WHERE `entry`=113112; -- Vol'jin
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15, `faction`=85, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=111935; -- Orgrimmar Grunt
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344 WHERE `entry`=100407; -- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2714, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=100467; -- Forsaken Deathguard
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=14720; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=14540; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=5196; -- Gray Riding Wolf
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `speed_walk`=1, `speed_run`=1.385714292526245117, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=11155; -- Brown Skeletal Horse
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=11154; -- Blue Skeletal Horse
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2714, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=100684; -- Silvermoon Citizen
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1.385714292526245117, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=12147; -- Riding Kodo (White)
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1.385714292526245117, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=12146; -- Riding Kodo (Olive)
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=12354; -- Brown Riding Kodo
UPDATE `creature_template` SET `gossip_menu_id`=19116, `minlevel`=45, `maxlevel`=45, `faction`=1665, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=35653632 WHERE `entry`=100636; -- High Overlord Saurfang
UPDATE `creature_template` SET `minlevel`=30, `RangeAttackTime`=0 WHERE `entry`=39380; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=30, `RangeAttackTime`=0 WHERE `entry`=39379; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=10685; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=42504; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=5951; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2714, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=100662; -- Denizen of Undercity
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=61751; -- Hare
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=3123; -- Bloodtalon Scythemaw
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=3127; -- Venomtail Scorpid
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2714, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=100664; -- Thunder Bluff Native
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2714, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=100679; -- Citizen of Kezan
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=3197; -- Burning Blade Fanatic
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=62116; -- Creepy Crawly
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=3198; -- Burning Blade Apprentice
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=3100; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2714, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=100682; -- Silvermoon Citizen
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2714, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=100502; -- Concerned Citizen
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2714, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=100663; -- Sen'jin Villager
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=86884; -- Darkspear Loyalist
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `RangeAttackTime`=0 WHERE `entry`=88750; -- Raptor
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2714, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=100453; -- Eitrigg
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=6145; -- School of Fish
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3148, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=160527; -- Mak
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3148, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=160526; -- Neri Sharpfin
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3148, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=160530; -- Friend Pronk
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3148, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=160529; -- Vim Brineheart
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3148, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=160528; -- Poen Gillbrack
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105176; -- Sathrovarr the Corruptor
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105169; -- Mephistroth
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105168; -- Anetheron
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105171; -- Mal'ganis
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105170; -- Balnazzar
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=90688; -- Tichondrius the Darkener
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111079; -- Dantalionax
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111154; -- Malgalor
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=91902; -- Brutallus
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105166; -- Gorgonnash
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105163; -- Destromath
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111089; -- Malinoth
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=92558; -- Arkethrax
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=4196352 WHERE `entry`=111153; -- Aargoss
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111152; -- Grand Summoner Abraxeton
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105192; -- Caria Felsoul
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105188; -- Cordana Felsong
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105190; -- Varedis Felsoul
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105185; -- Overseer Lykill
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105187; -- Azoran
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105186; -- Oublion
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105181; -- Lady Sacrolash
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105180; -- Grand Warlock Alythess
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105182; -- Gravax the Desecrator
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105179; -- Lord Jaraxxus
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111173; -- Soulchaser
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105189; -- Doomlord Kazrok
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105174; -- Smashspite the Hateful
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111088; -- Lord Perdition
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111167; -- Lochaber
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105197; -- Felwing
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105196; -- Brogozog
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111175; -- The Overseer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111174; -- Vaultwarden Umbra
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105183; -- Lord Kra'vos
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105175; -- Blerg
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105167; -- Imp Mother Fecunda
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111085; -- Geth'xun
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111087; -- Hakkar the Houndmaster
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111157; -- Pilik
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=111156; -- Fel Lord Dakuur
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105165; -- Felgard Legionnaire
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105164; -- Felgard Legionnaire
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=2, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4194304 WHERE `entry`=114280; -- Vizuul the Twisted
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4194304 WHERE `entry`=105205; -- Mo'arg Spinebreaker
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4194304 WHERE `entry`=105206; -- Wrathguard Dreadblade
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=105199; -- Felstalker Dreadhound
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4194304 WHERE `entry`=105200; -- Felguard Invader
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=111074; -- Grinning Shadowstalker
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags2`=4196352 WHERE `entry`=92801; -- Winged Nightmare
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=2, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4194304 WHERE `entry`=114753; -- Gorgoloth
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=2, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4194304 WHERE `entry`=114754; -- Mazgoroth
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=114760; -- Harbinger Faraleth
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=114763; -- Darkmagus Drazzok
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=4196352 WHERE `entry`=114756; -- Dread Knight Zak'gal
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=114758; -- Flamecaller Vezrah
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=4196352 WHERE `entry`=114755; -- Fel Lord Kaz'ral
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=114757; -- Flameweaver Verathix
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=114764; -- Darkmagus Falo'reth
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=114759; -- Harbinger Drel'nathar
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=114761; -- Arch Magus Velysra
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=114762; -- Arch Magus Zyrel
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2879, `npcflag`=17179869184, `speed_run`=1.828571438789367675, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=114469; -- Exodar Vindicator
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `speed_run`=1.828571438789367675, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=91949; -- Gnomeregan Tinkerer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_run`=1.828571438789367675, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=94209; -- Stormwind Knight
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_run`=1.828571438789367675, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=97503; -- Stormwind Knight
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `speed_run`=1.828571438789367675, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=92122; -- Gnomeregan Tinkerer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2879, `BaseAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=2099201, `unit_flags3`=8192 WHERE `entry`=110941; -- Desiccated Crusader
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2878, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=113129; -- Fel Lava
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2879, `BaseAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=2099201, `unit_flags3`=8192 WHERE `entry`=105217; -- Argent Dawnbringer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=90516; -- Mo'arg Painbringer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags2`=4196352 WHERE `entry`=90677; -- Wrathguard Dreadblade
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4194304 WHERE `entry`=105203; -- Felguard Invader
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113054; -- Diathorus the Seeker
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=294912, `unit_flags2`=2099200 WHERE `entry`=113055; -- Lord Banehollow
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2878, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=90544; -- Krosus
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113056; -- Solenor the Slayer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113058; -- Fel Lord Volak
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113057; -- Fel Lord Durkan
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=102706; -- Grinning Shadowstalker
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `HoverHeight`=1.5 WHERE `entry`=113053; -- Mother Sepestra
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=102696; -- Felslag Imp
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=90506; -- Felfire Imp
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113059; -- Fel Lord Garzan
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=102702; -- Wrathguard Dreadblade
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=91970; -- Felguard Invader
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=105172; -- Winged Nightmare
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=97510; -- Soulbound Destructor
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4194304 WHERE `entry`=92564; -- Mo'arg Painbringer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=1073743872 WHERE `entry`=101103; -- Command Ship
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2876, `BaseAttackTime`=2000, `unit_flags`=279296, `unit_flags2`=2048 WHERE `entry`=112976; -- Argent Lightbringer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=91967; -- Infernal Siegebreaker
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=102701; -- Mo'arg Painbringer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=94190; -- Burning Sentry
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=94189; -- Living Felblaze
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=94191; -- Burning Terrorhound
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2876, `BaseAttackTime`=2000, `unit_flags`=537150208, `unit_flags2`=2099201, `unit_flags3`=8192 WHERE `entry`=112977; -- Argent Lightbringer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=110617; -- Shadowsworn Harbinger
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=110616; -- Dark Worshipper
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2876, `BaseAttackTime`=2000, `unit_flags`=16640, `unit_flags2`=2099200 WHERE `entry`=97527; -- Argent Lightbringer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2876, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=97528; -- Argent Lightbringer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2028, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2097152, `VehicleId`=4536 WHERE `entry`=100959; -- Unattended Cannon
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=537166336, `unit_flags2`=2099201, `unit_flags3`=8224 WHERE `entry`=93708; -- Thunder Bluff Brave
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=537166336, `unit_flags2`=2099201, `unit_flags3`=8224 WHERE `entry`=97525; -- Thunder Bluff Brave
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=110618; -- Anchoring Crystal
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=4227072, `unit_flags3`=1 WHERE `entry`=101667; -- Shielded Anchor
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200 WHERE `entry`=90705; -- Dread Commander Arganoth
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2879, `speed_walk`=1.20000004768371582, `speed_run`=1.571428537368774414, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2099201, `unit_flags3`=8192 WHERE `entry`=101057; -- Gilnean Royal Guard
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1735, `npcflag`=1, `RangeAttackTime`=0, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=80221; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=97, `maxlevel`=97, `npcflag`=17179869185, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=83947; -- Kimzee Pinchwhistle
UPDATE `creature_template` SET `gossip_menu_id`=16296, `minlevel`=40, `maxlevel`=40, `npcflag`=17179873411, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=4196352, `unit_flags3`=32 WHERE `entry`=76872; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=80436; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=68719476739, `RangeAttackTime`=0, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=81688; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=40, `maxlevel`=40, `npcflag`=3, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=74808; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=80437; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=16593, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=79407; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=17052, `minlevel`=40, `maxlevel`=40, `npcflag`=129, `RangeAttackTime`=0, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=79619; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=93, `maxlevel`=93, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=88649; -- Draka
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=129, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=80151; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1801, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=89262; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=16797, `minlevel`=40, `maxlevel`=40, `npcflag`=3, `speed_walk`=1.799999952316284179, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=83858; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=17179869315, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=4196352, `unit_flags3`=32 WHERE `entry`=79774; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_run`=1, `RangeAttackTime`=0, `unit_flags2`=33556480, `unit_flags3`=1 WHERE `entry`=80776; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=93, `maxlevel`=93, `npcflag`=17179871360, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=80772; -- Sawame Brightburn
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81166; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=3, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=79740; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=16277, `minlevel`=93, `maxlevel`=93, `npcflag`=17179869827, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=76928; -- Kraank
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=17179869186, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=85882; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=16474, `minlevel`=90, `maxlevel`=90, `npcflag`=1, `RangeAttackTime`=0, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=80223; -- Lady Sena
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `RangeAttackTime`=0, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=80222; -- Mr. Pleeb
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0, `unit_flags2`=2099200 WHERE `entry`=80440; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_walk`=1, `RangeAttackTime`=0, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=78320; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=18757, `minlevel`=40, `maxlevel`=40, `faction`=190, `npcflag`=137438953473, `RangeAttackTime`=0, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=80432; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=40, `maxlevel`=40, `npcflag`=3, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=83482; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=17179869314, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=84967; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=17179869184, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=4196352, `unit_flags3`=32 WHERE `entry`=79916; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=80438; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=17179869184, `RangeAttackTime`=0, `unit_flags`=0, `unit_flags2`=4196352, `unit_flags3`=32 WHERE `entry`=79605; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=16801, `minlevel`=93, `maxlevel`=93, `npcflag`=17179869187, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=78487; -- Rokhan
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_walk`=3.20000004768371582, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=33570816, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=79603; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=190, `npcflag`=0, `RangeAttackTime`=0, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=80600; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=100, `maxlevel`=100, `npcflag`=3, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=78466; -- Gazlowe
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=17179869184, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=37750784, `unit_flags3`=32 WHERE `entry`=80299; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=17179869184, `RangeAttackTime`=0, `unit_flags`=0, `unit_flags2`=4196352, `unit_flags3`=32 WHERE `entry`=79925; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=93, `maxlevel`=93, `npcflag`=3, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=76411; -- Farseer Drek'Thar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=17179869184, `RangeAttackTime`=0, `unit_flags`=0, `unit_flags2`=4196352, `unit_flags3`=32 WHERE `entry`=80288; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=17179869184, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=37750784, `unit_flags3`=32 WHERE `entry`=79781; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=86470; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=45979; -- General Purpose Bunny JMF
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2876, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2099201, `unit_flags3`=8224 WHERE `entry`=90712; -- Earthen Ring Shaman
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2097152 WHERE `entry`=109604; -- Felguard Legionnaire
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2879, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=114466; -- Darnassus Sentinel
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113037; -- Fel Lord Darakk
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2131968 WHERE `entry`=113036; -- Fel Lord Razzar
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113038; -- Fel Lord Kurrz
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=97486; -- Gilnean Royal Guard
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2879, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=97496; -- Kirin Tor Battle-Mage
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=35653632, `unit_flags3`=1 WHERE `entry`=114863; -- General Purpose Bunny JMF (Look 2 - Flying, Huge AOI)
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200 WHERE `entry`=93719; -- Fel Commander Azgalor
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=112879; -- Horde Priest
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2876, `npcflag`=17179869184, `speed_walk`=1.20000004768371582, `speed_run`=1.571428537368774414, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=114479; -- Silvermoon Blood Knight
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33554496, `unit_flags2`=2113536, `unit_flags3`=1 WHERE `entry`=92061; -- Cannon
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2099201, `unit_flags3`=8192 WHERE `entry`=108990; -- Stormwind Gryphon
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=93219; -- Gilnean Royal Guard
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2876, `npcflag`=17179869184, `speed_walk`=1.20000004768371582, `speed_run`=1.571428537368774414, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2099201, `unit_flags3`=8224 WHERE `entry`=93704; -- Darkspear Headhunter
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2097152 WHERE `entry`=109591; -- Felguard Legionnaire
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2099201, `unit_flags3`=8192 WHERE `entry`=113290; -- Riding Bat
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2876, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=112921; -- Bilgewater Blastmaster
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2876, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=97521; -- Earthen Ring Shaman
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2879, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=92586; -- Ironforge Cannoneer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=109587; -- Fel Lord Zardak
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2879, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=91353; -- Kirin Tor Battle-Mage
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=35653632, `unit_flags3`=1 WHERE `entry`=72973; -- General Purpose Bunny JMF (Look 2, Huge AOI)
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2097152 WHERE `entry`=90686; -- Felstalker Dreadhound
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2097152 WHERE `entry`=109592; -- Felguard Legionnaire
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33554432 WHERE `entry`=109494; -- Anchor Vehicle
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2097152, `unit_flags3`=1 WHERE `entry`=91704; -- Anchoring Crystal
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `unit_flags3`=32 WHERE `entry`=90717; -- Genn Greymane
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `unit_flags3`=32 WHERE `entry`=90714; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `unit_flags3`=32 WHERE `entry`=90711; -- Thrall
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `unit_flags3`=32 WHERE `entry`=90708; -- Vol'jin
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=1073743872 WHERE `entry`=91951; -- Highlord Tirion Fordring
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=1073743872, `unit_flags3`=32 WHERE `entry`=90713; -- King Varian Wrynn
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=1073743872, `unit_flags3`=32 WHERE `entry`=90709; -- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=1073743872, `unit_flags3`=32 WHERE `entry`=90710; -- Baine Bloodhoof
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=112924; -- Captain Russo
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=94276; -- Gul'dan
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=33554432 WHERE `entry`=55091; -- General Purpose Bunny JMF (Look 2 - Flying, Infinite AOI)
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=1073743872, `unit_flags3`=32, `VehicleId`=1320 WHERE `entry`=90716; -- Gelbin Mekkatorque
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=1073743872 WHERE `entry`=109341; -- General Purpose Bunny JMF
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=114250; -- Gelbin Mekkatorque
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1768, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=1073743873, `unit_flags3`=8192 WHERE `entry`=101632; -- Mo'arg Painbringer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=1073743872 WHERE `entry`=90525; -- Eredar Chaos Guard
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1835, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113341; -- Deck Hand
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=112923; -- Du'pre
UPDATE `creature_template` SET `gossip_menu_id`=20306, `minlevel`=45, `maxlevel`=45, `faction`=125, `npcflag`=3, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113118; -- Captain Russo
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=41621; -- Commander Thorak
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=125, `npcflag`=129, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113151; -- Fo'rum the Postmaker
UPDATE `creature_template` SET `minlevel`=-15, `maxlevel`=-15, `faction`=85, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113547; -- Stone Guard Mukar
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0 WHERE `entry`=40893; -- Dranosh'ar Fisherman
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=29, `npcflag`=129, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=113616; -- Garyl
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=877, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=113615; -- Ravika
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=67125248, `unit_flags3`=1 WHERE `entry`=112922; -- Cannon-In-A-Box
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114134; -- Doomsayer
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112920; -- Dark Ranger
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114132; -- Doomsayer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113959; -- Shappa
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113947; -- Maska
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114133; -- Doomsayer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113960; -- Arcanist Druk'rog
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113946; -- Karn Steelhoof
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113945; -- Omril Keenedge
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113544; -- Neejala
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113542; -- Marius Sunshard
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114106; -- Sergeant Grimjaw
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113545; -- Dawn Mercurus
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113543; -- Annix Strifesprocket
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113546; -- Yaalo
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113961; -- Pinkee Rizzo
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113948; -- Arienne Black
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113949; -- Rizza Brassrokkit
UPDATE `creature_template` SET `gossip_menu_id`=19861, `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113950; -- Lonan
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113951; -- Sahale
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113955; -- Utona Wolfeye
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113956; -- Taela Shatterborne
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113953; -- Faala
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113957; -- Ja'kala
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=14729; -- Ralston Farnsley
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113952; -- Aila Dourblade
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113958; -- Handel Shadereaver
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=113954; -- Argonis Solheart
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=131072, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=108420; -- Training Dummy
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114107; -- Lan'veros Furybrand
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114108; -- Merhean Sunfall
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113541; -- Seleria Dawncaller
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114135; -- Bilgewater Blastmaster
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114136; -- Bilgewater Blastmaster
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113550; -- Rakkaha
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113549; -- Sulaka
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113551; -- Ja'kala
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113548; -- Mojo'kai
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113539; -- Orgek Ironhand
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=97526; -- Deathguard Elite
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114105; -- Kinja
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2876, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113034; -- Darkspear Headhunter
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2162, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113997; -- Megaton
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1835, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114114; -- Gregg
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113540; -- Liu-So
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2110, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114068; -- Ju-Shan
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1835, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113374; -- Horde Recruit
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1835, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113375; -- Horde Recruit
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1835, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113373; -- Horde Recruit
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=4311; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `speed_run`=4.285714149475097656, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=114067; -- Darkspear Bat Rider
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1835, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113377; -- Horde Recruit
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1835, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113331; -- Horde Recruit
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113291; -- Wind Rider
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=114131; -- Target
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1835, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113376; -- Horde Recruit
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1835, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113380; -- Horde Recruit
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=114066; -- Orgrimmar Wind Rider
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1835, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113381; -- Horde Recruit
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=3319; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=16, `RangeAttackTime`=0 WHERE `entry`=37072; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=46358; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=46512; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `npcflag`=17, `RangeAttackTime`=0 WHERE `entry`=46357; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=46359; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0 WHERE `entry`=44160; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0 WHERE `entry`=34765; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=3334; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `npcflag`=2, `RangeAttackTime`=0 WHERE `entry`=3328; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=2, `RangeAttackTime`=0 WHERE `entry`=47233; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0 WHERE `entry`=26537; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=3330; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=5816; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=2, `RangeAttackTime`=0 WHERE `entry`=44735; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=2, `RangeAttackTime`=0 WHERE `entry`=44725; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=45230; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=3189; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=3327; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=158637; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=10880; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=149616; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=-25, `maxlevel`=-25 WHERE `entry`=64584; -- Dawnchaser Brave
UPDATE `creature_template` SET `minlevel`=-25, `maxlevel`=-25 WHERE `entry`=67014; -- Warpweaver Shafiee
UPDATE `creature_template` SET `minlevel`=-25, `maxlevel`=-25 WHERE `entry`=67013; -- Vaultkeeper Meelad
UPDATE `creature_template` SET `minlevel`=-25, `maxlevel`=-25 WHERE `entry`=68981; -- Voidbinder Shadzor
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=55336; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=85798; -- Golden Dawnfeather
UPDATE `creature_template` SET `npcflag`=1073741824, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=85007; -- Thicket Skitterer
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=80589; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_run`=4.285714149475097656, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=82512; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82558; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=4194433, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=82553; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=83797; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=8192, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82511; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=82508; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=83930; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=84054; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=82568; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=83786; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82183; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=83921; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=65665, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=82516; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `VehicleId`=3700 WHERE `entry`=82566; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=83902; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=84093; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82467; -- Krixel Pinchwhistle
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2755, `npcflag`=3, `RangeAttackTime`=0, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82468; -- Kimzee Pinchwhistle
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=48340; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=82567; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82552; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=83744; -- Rescued Crewman
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82554; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=83884; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=83703; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=83854; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=83938; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=83920; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82555; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2000, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.10000002384185791 WHERE `entry`=88587; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=83944; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=83908; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=83891; -- Gearworks Crab
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=84856; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=82243; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1771, `BaseAttackTime`=3000, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=87087; -- Bulbapore
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=67108865, `unit_flags3`=8193, `dynamicflags`=128 WHERE `entry`=81135; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=67143680, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=81288; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=82272; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81138; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=88578; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1140852738 WHERE `entry`=89356; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=85403; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=88426; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81168; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=61312; -- Strand Crab
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `RangeAttackTime`=0, `unit_flags`=768, `unit_flags2`=2048, `VehicleId`=0 WHERE `entry`=81567; -- Repaired Flying Machine
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2335, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=85793; -- Cured Goblin
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_walk`=1.20000004768371582, `speed_run`=0.428571432828903198, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=84887; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=85325; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=82253; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=88359; -- Swamplighter Firefly
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=1412; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `RangeAttackTime`=0, `unit_flags`=33587968, `unit_flags2`=1073776640, `unit_flags3`=1 WHERE `entry`=88419; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `RangeAttackTime`=0, `unit_flags`=768, `unit_flags2`=67110912, `dynamicflags`=128 WHERE `entry`=81632; -- Firebomb
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=88988; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=81566; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=16993, `minlevel`=40, `maxlevel`=40, `faction`=2755, `npcflag`=3, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81978; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=3000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=82265; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=16596, `minlevel`=97, `maxlevel`=97, `npcflag`=3, `RangeAttackTime`=0, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=81443; -- Krixel Pinchwhistle
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=81184; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=4224, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=82182; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=85647; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.190000057220458984 WHERE `entry`=85417; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=88481; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=6827; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480, `dynamicflags`=4 WHERE `entry`=81183; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81524; -- -Unknown-

UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=40522; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=42431; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=43241; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=38842; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=40316; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=39371; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=40050; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=38372; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=37779; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=37965; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=40111; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=7100 WHERE `ID`=37466; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=18925, `RewardBonusMoney`=450, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=58122; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=189240, `RewardBonusMoney`=3550 WHERE `ID`=31724; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2460, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=13961; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2900, `Flags`=134217736, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=28854; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2900, `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=28852; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2900, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=28853; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=925, `FlagsEx`=2097344, `VerifiedBuild`=38134 WHERE `ID`=46293; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=189240, `RewardBonusMoney`=3550, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=45083; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=40329; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=189240, `RewardBonusMoney`=3550, `FlagsEx`=3147968, `VerifiedBuild`=38134 WHERE `ID`=38300; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=189240, `RewardBonusMoney`=3550, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=36471; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=189240, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=33137; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=189240, `RewardBonusMoney`=3550, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=32863; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=189240, `RewardBonusMoney`=3550, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=31921; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=189240, `RewardBonusMoney`=3550 WHERE `ID`=31916; -- -Unknown-
UPDATE `quest_template` SET `RewardSpell`=179783, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=36614; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29688; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29542; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=600, `Flags`=0, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=10835; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2460, `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=10390; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2460, `Flags`=0, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=10258; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=600, `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=10213; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=300, `Flags`=8, `FlagsEx`=2097216, `AllowableRaces`=1308635570, `VerifiedBuild`=38134 WHERE `ID`=9498; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2460, `Flags`=12, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=9400; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=40518; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=44281; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=725, `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=26293; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2900 WHERE `ID`=25924; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2367552, `VerifiedBuild`=38134 WHERE `ID`=36062; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=35298; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=36428; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=35211; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=35091; -- -Unknown-


UPDATE `quest_objectives` SET `Description`='Pledge to Warchief Sylvanas', `VerifiedBuild`=38134 WHERE `ID`=281058; -- 281058
UPDATE `quest_objectives` SET `Description`='Learn the Fate of the Horde', `VerifiedBuild`=38134 WHERE `ID`=281003; -- 281003
UPDATE `quest_objectives` SET `Description`='Enter Grommash Hold', `VerifiedBuild`=38134 WHERE `ID`=280861; -- 280861
UPDATE `quest_objectives` SET `Description`='Report to Saurfang', `VerifiedBuild`=38134 WHERE `ID`=280860; -- 280860
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=264309; -- 264309
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=264308; -- 264308
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=265447; -- 265447
UPDATE `quest_objectives` SET `Description`='Trogg Dweller slain', `VerifiedBuild`=38134 WHERE `ID`=266526; -- 266526
UPDATE `quest_objectives` SET `Description`='Twilight\'s Hammer Minion slain', `VerifiedBuild`=38134 WHERE `ID`=266525; -- 266525
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=265089; -- 265089
UPDATE `quest_objectives` SET `Description`='Defeat Crysa', `VerifiedBuild`=38134 WHERE `ID`=287526; -- 287526
UPDATE `quest_objectives` SET `Description`='Pet Battlemasters Defeated', `VerifiedBuild`=38134 WHERE `ID`=280702; -- 280702
UPDATE `quest_objectives` SET `Description`='Defeat Kura Thunderhoof', `VerifiedBuild`=38134 WHERE `ID`=277664; -- 277664
UPDATE `quest_objectives` SET `Description`='Defeat Christoph VonFeasel', `VerifiedBuild`=38134 WHERE `ID`=274798; -- 274798
UPDATE `quest_objectives` SET `Description`='Celestial Tournament won', `VerifiedBuild`=38134 WHERE `ID`=270923; -- 270923
UPDATE `quest_objectives` SET `Description`='Win PvP Pet Battles', `VerifiedBuild`=38134 WHERE `ID`=270529; -- 270529
UPDATE `quest_objectives` SET `Description`='Defeat Morulu the Elder', `VerifiedBuild`=38134 WHERE `ID`=269217; -- 269217
UPDATE `quest_objectives` SET `Description`='Defeat Narrok', `VerifiedBuild`=38134 WHERE `ID`=269216; -- 269216
UPDATE `quest_objectives` SET `Description`='Defeat Ras\'an', `VerifiedBuild`=38134 WHERE `ID`=269215; -- 269215
UPDATE `quest_objectives` SET `Description`='Defeat Nicki Tinytech', `VerifiedBuild`=38134 WHERE `ID`=269214; -- 269214
UPDATE `quest_objectives` SET `Description`='Upgrade your garrison to Tier 3', `VerifiedBuild`=38134 WHERE `ID`=274979; -- 274979
UPDATE `quest_objectives` SET `Description`='Garrison resources gathered', `VerifiedBuild`=38134 WHERE `ID`=275472; -- 275472
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=253937; -- 253937
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=257671; -- 257671
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=257670; -- 257670
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=260771; -- 260771
UPDATE `quest_objectives` SET `Description`='Broken Shore assaulted', `VerifiedBuild`=38134 WHERE `ID`=283013; -- 283013
UPDATE `quest_objectives` SET `Description`='Ship taken to the Broken Shore', `VerifiedBuild`=38134 WHERE `ID`=286345; -- 286345
UPDATE `quest_objectives` SET `Description`='Warmed up with a duel', `VerifiedBuild`=38134 WHERE `ID`=286487; -- 286487
UPDATE `quest_objectives` SET `Description`='Last meal eaten', `VerifiedBuild`=38134 WHERE `ID`=286486; -- 286486
UPDATE `quest_objectives` SET `Description`='Weapon empowered', `VerifiedBuild`=38134 WHERE `ID`=286485; -- 286485
UPDATE `quest_objectives` SET `Description`='Armor polished', `VerifiedBuild`=38134 WHERE `ID`=286484; -- 286484
UPDATE `quest_objectives` SET `Description`='Ride on Kimzee\'s Flying Machine', `VerifiedBuild`=38134 WHERE `ID`=273955; -- 273955
UPDATE `quest_objectives` SET `Description`='Plunger Activated', `VerifiedBuild`=38134 WHERE `ID`=273704; -- 273704
UPDATE `quest_objectives` SET `Description`='Infected Goblins Cured', `VerifiedBuild`=38134 WHERE `ID`=274760; -- 274760
UPDATE `quest_objectives` SET `Description`='Firebombs Placed', `VerifiedBuild`=38134 WHERE `ID`=273580; -- 273580
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273436; -- 273436


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=281058 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=280860 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274798 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=270923 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269217 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269216 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269215 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269214 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274979 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=286345 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=286486 AND `Index`=5);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=286486 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=286486 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=286486 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=286486 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=286486 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=286485 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=286484 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274760 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274760 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274760 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274760 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274760 AND `Index`=0);


UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=36062 AND `Idx`=0);


UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64058; -- Jorunga Stonehoof
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64059; -- Razzie Coalwrench
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=91353; -- Kirin Tor Battle-Mage
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64060; -- Tixit Brightfuse
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=72973; -- General Purpose Bunny JMF (Look 2, Huge AOI)
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64062; -- Gentle Dari
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64064; -- Vanaris Whitesong
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64065; -- Brewmaster Roland
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114753; -- Gorgoloth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=97486; -- Gilnean Royal Guard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85789; -- Cured Goblin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64066; -- Brewmaster Vudia
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114754; -- Mazgoroth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64067; -- Barleyflower
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114755; -- Fel Lord Kaz'ral
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=11154; -- Blue Skeletal Horse
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114756; -- Dread Knight Zak'gal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=11155; -- Brown Skeletal Horse
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114757; -- Flameweaver Verathix
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85793; -- Cured Goblin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114758; -- Flamecaller Vezrah
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114759; -- Harbinger Drel'nathar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=6145; -- School of Fish
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114760; -- Harbinger Faraleth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114761; -- Arch Magus Velysra
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114762; -- Arch Magus Zyrel
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114763; -- Darkmagus Drazzok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=97496; -- Kirin Tor Battle-Mage
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114764; -- Darkmagus Falo'reth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=52382; -- Ziradormi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=97503; -- Stormwind Knight
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100848; -- Darkspear Guardian
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82467; -- Krixel Pinchwhistle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100849; -- Sunwalker Atohmo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82468; -- Kimzee Pinchwhistle
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=45709; -- Bruiser Janx
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100852; -- Orgrimmar Grunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=97510; -- Soulbound Destructor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100855; -- Thunder Bluff Brave
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100856; -- Ceremonial Watcher
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=113112; -- Vol'jin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=47944; -- Dark Phoenix Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=91949; -- Gnomeregan Tinkerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=97521; -- Earthen Ring Shaman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=91951; -- Highlord Tirion Fordring
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113118; -- Captain Russo
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100865; -- Sen'jin Spirit Drummer
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100866; -- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100867; -- Lor'themar Theron
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=97525; -- Thunder Bluff Brave
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=97526; -- Deathguard Elite
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=64106; -- Erin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=97527; -- Argent Lightbringer
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=64107; -- Sadi
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100870; -- Baine Bloodhoof
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=97528; -- Argent Lightbringer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=62996; -- Madam Vee Luo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100873; -- Allari the Souleater
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=94189; -- Living Felblaze
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85834; -- Krixel Pinchwhistle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100874; -- Illidari Enforcer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=94190; -- Burning Sentry
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113129; -- Fel Lava
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=94191; -- Burning Terrorhound
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113130; -- Burning Sentry
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64114; -- Joan Tremblay
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113131; -- Living Felblaze
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113132; -- Burning Terrorhound
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=91967; -- Infernal Siegebreaker
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=64118; -- Erni Tanboshi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85842; -- Kimzee Pinchwhistle
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=64119; -- Dirki Tanboshi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=91970; -- Felguard Invader
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114250; -- Gelbin Mekkatorque
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85843; -- Cured Goblin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64121; -- Eli
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85845; -- Cured Goblin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64122; -- Andrew Vestal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63008; -- Brewmaster Skye
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112584; -- Master Gadrin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112585; -- Lady Liadrin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64126; -- Stephen Wong
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112586; -- Nathanos Blightcaller
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112587; -- Gamon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112588; -- Grand Magister Rommath
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112589; -- Vanira
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112590; -- High Overlord Saurfang
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=94209; -- Stormwind Knight
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=64131; -- Evangelia
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112591; -- Shadow Hunter Spar'kuhl
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112592; -- Shadow Hunter Gar'ant
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112593; -- Shadow Hunter Kajassa
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64134; -- Jontan Dum'okk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112594; -- Tyrathan Khort
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113151; -- Fo'rum the Postmaker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112598; -- Dark Ranger Velonara
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112599; -- Dark Ranger Alina
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112600; -- Dark Ranger Lyana
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112601; -- Dark Ranger Kalira
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112602; -- Dark Ranger Anya
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112607; -- Yelmak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112608; -- Magister Savarin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114280; -- Vizuul the Twisted
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=92558; -- Arkethrax
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=175551; -- Stonewrought Sentry
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=65266; -- David Harrington
UPDATE `creature_template` SET `name`='Desiccated Crusader', `VerifiedBuild`=38134 WHERE `entry`=110941; -- Desiccated Crusader
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=12354; -- Brown Riding Kodo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=92564; -- Mo'arg Painbringer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160526; -- Neri Sharpfin
UPDATE `creature_template` SET `movementId`=69, `VerifiedBuild`=38134 WHERE `entry`=86445; -- Land Shark
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160527; -- Mak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85889; -- Kimzee Pinchwhistle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160528; -- Poen Gillbrack
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160529; -- Vim Brineheart
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160530; -- Friend Pronk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114863; -- General Purpose Bunny JMF (Look 2 - Flying, Huge AOI)
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=92586; -- Ironforge Cannoneer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=93704; -- Darkspear Headhunter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65856; -- Ba'kon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=93708; -- Thunder Bluff Brave
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65859; -- Beige Sugar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65862; -- Ala'thinel
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81458; -- Krixel Pinchwhistle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100959; -- Unattended Cannon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=93719; -- Fel Commander Azgalor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=94276; -- Gul'dan
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100405; -- Baine Bloodhoof
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100406; -- Ji Firepaw
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100407; -- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=73674; -- Blizzix Sparkshiv
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100413; -- Dark Ranger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=7952; -- Zjolnir
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=92061; -- Cannon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66998; -- Jinho the Wind Breaker
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=121, `VerifiedBuild`=38134 WHERE `entry`=34694; -- Grunty
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=109341; -- General Purpose Bunny JMF
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `unit_class`=8, `VerifiedBuild`=38134 WHERE `entry`=67013; -- Vaultkeeper Meelad
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `unit_class`=8, `VerifiedBuild`=38134 WHERE `entry`=67014; -- Warpweaver Shafiee
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=38134 WHERE `entry`=73699; -- Tiny Bunny - GJC
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100442; -- Vol'jin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=5196; -- Gray Riding Wolf
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=88750; -- Raptor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112706; -- Aethas Sunreaver
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100453; -- Eitrigg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=83744; -- Rescued Crewman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=87087; -- Bulbapore
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=93219; -- Gilnean Royal Guard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100464; -- Earthen Ring Shaman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100466; -- Thunder Bluff Brave
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100467; -- Forsaken Deathguard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=102696; -- Felslag Imp
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=102701; -- Mo'arg Painbringer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=102702; -- Wrathguard Dreadblade
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112730; -- Orgrimmar Grunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=92122; -- Gnomeregan Tinkerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=102706; -- Grinning Shadowstalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113290; -- Riding Bat
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=103822; -- Treant
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113291; -- Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=45340; -- Fossilized Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111074; -- Grinning Shadowstalker
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=101606; -- Trade Prince Gallywix
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=40893; -- Dranosh'ar Fisherman
UPDATE `creature_template` SET `movementId`=121, `VerifiedBuild`=38134 WHERE `entry`=58163; -- Soul of the Aspects
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111079; -- Dantalionax
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=101056; -- Gilnean Royal Guard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=91588; -- Fel Lord Kurduz
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=101057; -- Gilnean Royal Guard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100502; -- Concerned Citizen
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111085; -- Geth'xun
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111087; -- Hakkar the Houndmaster
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111088; -- Lord Perdition
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81567; -- Repaired Flying Machine
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111089; -- Malinoth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=14729; -- Ralston Farnsley
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81574; -- Kimzee Pinchwhistle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63753; -- Wounded Defender
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=175156; -- Voidwalker Minion
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=101632; -- Mo'arg Painbringer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113331; -- Horde Recruit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113341; -- Deck Hand
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90506; -- Felfire Imp
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114466; -- Darnassus Sentinel
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90516; -- Mo'arg Painbringer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114469; -- Exodar Vindicator
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=101103; -- Command Ship
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=62116; -- Creepy Crawly
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=67130; -- D.E.N.T.
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90525; -- Eredar Chaos Guard
UPDATE `creature_template` SET `type_flags`=16, `VerifiedBuild`=38134 WHERE `entry`=101667; -- Shielded Anchor
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=67133; -- Andy
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=103896; -- Felfire Imp
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114479; -- Silvermoon Blood Knight
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=67134; -- Kat
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=103897; -- Fiery Trickster
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=103898; -- Sickly Imp
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=103899; -- Shadowflame Imp
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113373; -- Horde Recruit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113374; -- Horde Recruit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113375; -- Horde Recruit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=45979; -- General Purpose Bunny JMF
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113376; -- Horde Recruit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113377; -- Horde Recruit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111152; -- Grand Summoner Abraxeton
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113380; -- Horde Recruit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111153; -- Aargoss
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90544; -- Krosus
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113381; -- Horde Recruit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81632; -- Firebomb
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111154; -- Malgalor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64924; -- Guyo Crystalgear
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111156; -- Fel Lord Dakuur
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64925; -- Tivilix Bangalter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111157; -- Pilik
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113945; -- Omril Keenedge
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113946; -- Karn Steelhoof
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113947; -- Maska
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=96123; -- Blazing Firehawk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113948; -- Arienne Black
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113949; -- Rizza Brassrokkit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=109494; -- Anchor Vehicle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113950; -- Lonan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=3108; -- Encrusted Surf Crawler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113951; -- Sahale
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111167; -- Lochaber
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113952; -- Aila Dourblade
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113953; -- Faala
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113954; -- Argonis Solheart
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113955; -- Utona Wolfeye
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113956; -- Taela Shatterborne
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113957; -- Ja'kala
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111173; -- Soulchaser
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=110616; -- Dark Worshipper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113958; -- Handel Shadereaver
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111174; -- Vaultwarden Umbra
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=110617; -- Shadowsworn Harbinger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113959; -- Shappa
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=111175; -- The Overseer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=110618; -- Anchoring Crystal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113960; -- Arcanist Druk'rog
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113961; -- Pinkee Rizzo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=3123; -- Bloodtalon Scythemaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=92801; -- Winged Nightmare
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=110627; -- Gilnean Druid
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=3127; -- Venomtail Scorpid
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=110628; -- Stormwind Priest
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=110629; -- Kirin Tor Battle-Mage
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=110630; -- Kirin Tor Battle-Mage
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=110631; -- Gnomeregan Tinkerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=110632; -- Gnomeregan Tinkerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=110633; -- Stormwind Knight
UPDATE `creature_template` SET `rank`=1, `family`=35, `VerifiedBuild`=38134 WHERE `entry`=64403; -- Alani
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=91704; -- Anchoring Crystal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112876; -- Silvermoon Priest
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=108420; -- Training Dummy
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112877; -- Thunder Bluff Brave
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130145; -- Warchief's Herald
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112879; -- Horde Priest
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=97285; -- Wind Rush Totem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=38244; -- Legati
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113997; -- Megaton
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=108990; -- Stormwind Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100636; -- High Overlord Saurfang
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=95072; -- Greater Earth Elemental
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=174170; -- Maw Haunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112902; -- Earthen Ring Shaman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=83947; -- Kimzee Pinchwhistle
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=100660; -- Lor'themar Theron
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100662; -- Denizen of Undercity
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100663; -- Sen'jin Villager
UPDATE `creature_template` SET `HealthScalingExpansion`=2, `VerifiedBuild`=38134 WHERE `entry`=41621; -- Commander Thorak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100664; -- Thunder Bluff Native
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112920; -- Dark Ranger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112921; -- Bilgewater Blastmaster
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=115149; -- Soulbroken Whelpling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112922; -- Cannon-In-A-Box
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112923; -- Du'pre
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112924; -- Captain Russo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=3197; -- Burning Blade Fanatic
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=3198; -- Burning Blade Apprentice
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=109587; -- Fel Lord Zardak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100679; -- Citizen of Kezan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=109591; -- Felguard Legionnaire
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=109592; -- Felguard Legionnaire
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100682; -- Silvermoon Citizen
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100684; -- Silvermoon Citizen
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=109604; -- Felguard Legionnaire
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114066; -- Orgrimmar Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114067; -- Darkspear Bat Rider
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114068; -- Ju-Shan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90677; -- Wrathguard Dreadblade
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105163; -- Destromath
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105164; -- Felgard Legionnaire
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=66731; -- Mr. Creasey
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=12146; -- Riding Kodo (Olive)
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105165; -- Felgard Legionnaire
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=12147; -- Riding Kodo (White)
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105166; -- Gorgonnash
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105167; -- Imp Mother Fecunda
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105168; -- Anetheron
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90686; -- Felstalker Dreadhound
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105169; -- Mephistroth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105170; -- Balnazzar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90688; -- Tichondrius the Darkener
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105171; -- Mal'ganis
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=73422; -- Miss Jadepaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105172; -- Winged Nightmare
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105174; -- Smashspite the Hateful
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=113529; -- Warchief Vol'jin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105175; -- Blerg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100720; -- Trade Prince Gallywix
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105176; -- Sathrovarr the Corruptor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100721; -- Bilgewater Soldier
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112976; -- Argent Lightbringer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105179; -- Lord Jaraxxus
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=112977; -- Argent Lightbringer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105180; -- Grand Warlock Alythess
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105181; -- Lady Sacrolash
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105182; -- Gravax the Desecrator
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105183; -- Lord Kra'vos
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100728; -- Eitrigg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113539; -- Orgek Ironhand
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105185; -- Overseer Lykill
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113540; -- Liu-So
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100730; -- Zor Lonetree
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105186; -- Oublion
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113541; -- Seleria Dawncaller
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `unit_class`=8, `VerifiedBuild`=38134 WHERE `entry`=68981; -- Voidbinder Shadzor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100731; -- Gotura Fourwinds
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105187; -- Azoran
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90705; -- Dread Commander Arganoth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113542; -- Marius Sunshard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105188; -- Cordana Felsong
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113543; -- Annix Strifesprocket
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105189; -- Doomlord Kazrok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113544; -- Neejala
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=68984; -- Ruben Holen
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105190; -- Varedis Felsoul
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90708; -- Vol'jin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113545; -- Dawn Mercurus
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90709; -- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113546; -- Yaalo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105192; -- Caria Felsoul
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90710; -- Baine Bloodhoof
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=113547; -- Stone Guard Mukar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90711; -- Thrall
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113548; -- Mojo'kai
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114105; -- Kinja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90712; -- Earthen Ring Shaman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114106; -- Sergeant Grimjaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113549; -- Sulaka
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90713; -- King Varian Wrynn
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114107; -- Lan'veros Furybrand
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113550; -- Rakkaha
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105196; -- Brogozog
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90714; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114108; -- Merhean Sunfall
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113551; -- Ja'kala
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=38134 WHERE `entry`=61751; -- Hare
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105197; -- Felwing
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90716; -- Gelbin Mekkatorque
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105199; -- Felstalker Dreadhound
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90717; -- Genn Greymane
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105200; -- Felguard Invader
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114114; -- Gregg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=74010; -- Nadina Stargem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105203; -- Felguard Invader
UPDATE `creature_template` SET `HealthModifier`=19, `VerifiedBuild`=38134 WHERE `entry`=74012; -- Ki'agnuu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105205; -- Mo'arg Spinebreaker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105206; -- Wrathguard Dreadblade
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=93514; -- Generic Stalker
UPDATE `creature_template` SET `HealthModifier`=20, `VerifiedBuild`=38134 WHERE `entry`=74019; -- Tu'aho Pathcutter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105217; -- Argent Dawnbringer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114131; -- Target
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114132; -- Doomsayer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55091; -- General Purpose Bunny JMF (Look 2 - Flying, Infinite AOI)
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114133; -- Doomsayer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114134; -- Doomsayer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64561; -- Jong Ming-Yiu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114135; -- Bilgewater Blastmaster
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=114136; -- Bilgewater Blastmaster
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=3297; -- Sen'jin Watcher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=3304; -- Master Vornal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113034; -- Darkspear Headhunter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64575; -- Chan Hoi-San
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113035; -- Darkspear Witch Doctor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113036; -- Fel Lord Razzar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113037; -- Fel Lord Darakk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64578; -- Jong Jun-Keet
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113038; -- Fel Lord Kurrz
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64579; -- Jong Wik-Wung
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=64584; -- Dawnchaser Brave
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64588; -- Armorer Relna
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=111935; -- Orgrimmar Grunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113053; -- Mother Sepestra
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113054; -- Diathorus the Seeker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64038; -- Marli Two-Toes
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113055; -- Lord Banehollow
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64039; -- Hoka Stonecrush
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113056; -- Solenor the Slayer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64040; -- Tina Wang
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113057; -- Fel Lord Durkan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64041; -- Mifan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113058; -- Fel Lord Volak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113615; -- Ravika
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113059; -- Fel Lord Garzan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=113616; -- Garyl
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64043; -- Uncle Gus
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=86884; -- Darkspear Loyalist
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64047; -- Kurong Caskhead
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64049; -- Victor Pearce
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82431; -- Repaired Flying Machine
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64050; -- Derenda Enkleshin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64051; -- Esha the Loommaiden
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=91902; -- Brutallus
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64053; -- Fang Whitescroll
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64054; -- Krogo Darkhide


UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=6145 AND `Idx`=0); -- School of Fish


UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245878; -- Funeral Pyre
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245881; -- Troll Banner
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245865; -- Horde Banner
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245864; -- Troll Banner
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=258064; -- Funeral Pyre
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=216056; -- Collision PC Size
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245876; -- Candle
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245866; -- Troll Drum
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245880; -- Incense
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245871; -- Flowers
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245863; -- Torch
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245870; -- Flowers
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245875; -- Mat
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245869; -- Flowers
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=252281; -- Supplies
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243302; -- Trap
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243300; -- Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243292; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243299; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243293; -- Barricade
UPDATE `gameobject_template` SET `Data2`=1, `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=245730; -- Reinforced Gate
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=246039; -- Protective Barrier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204175; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204174; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204173; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204172; -- Brazier
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=3879, `ContentTuningId`=70, `VerifiedBuild`=38134 WHERE `entry`=58595; -- Burning Blade Stash
UPDATE `gameobject_template` SET `IconName`='', `VerifiedBuild`=38134 WHERE `entry`=1619; -- Earthroot
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204171; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204170; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204167; -- Brazier
UPDATE `gameobject_template` SET `Data0`=2863, `VerifiedBuild`=38134 WHERE `entry`=1731; -- Copper Vein
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204168; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204169; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=254234; -- WMO Bridge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=242549; -- WMO Bridge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=241535; -- Bleakthorn
UPDATE `gameobject_template` SET `ContentTuningId`=436, `VerifiedBuild`=38134 WHERE `entry`=241536; -- Moongrass
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=241523; -- Felbloom
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=241537; -- Chaos Clover
UPDATE `gameobject_template` SET `ContentTuningId`=436, `VerifiedBuild`=38134 WHERE `entry`=241538; -- Doom Shroom
UPDATE `gameobject_template` SET `type`=10, `displayId`=26854, `size`=0.75, `Data10`=182420, `Data13`=1, `Data25`=1, `ContentTuningId`=1207, `VerifiedBuild`=38134 WHERE `entry`=248819; -- Legion Cage
UPDATE `gameobject_template` SET `type`=10, `displayId`=26854, `IconName`='questinteract', `castBarCaption`='Unlocking', `size`=0.75, `Data0`=1691, `Data1`=0, `Data3`=3000, `Data10`=182420, `Data13`=1, `Data14`=24815, `Data23`=1, `ContentTuningId`=1207, `VerifiedBuild`=38134 WHERE `entry`=240535; -- Legion Cage
UPDATE `gameobject_template` SET `Data10`=173847, `Data17`=1, `Data20`=1, `VerifiedBuild`=38134 WHERE `entry`=237191; -- Garrison Cache
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=38134 WHERE `entry`=251426; -- Fel Fire
UPDATE `gameobject_template` SET `type`=10, `displayId`=37460, `Data13`=1, `Data18`=1, `ContentTuningId`=1207, `VerifiedBuild`=38134 WHERE `entry`=240194; -- Spire of Woe
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=255203; -- Horde Battleship
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=251604; -- Alliance Battleship
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=254275; -- Legion Portal Large
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=254017; -- Legion Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=240211; -- Legion Gateway
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=254251; -- Legion Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=254016; -- Legion Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=254018; -- Legion Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=254250; -- Legion Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=240214; -- Siege Cannon
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=254015; -- Legion Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=254252; -- Legion Portal
UPDATE `gameobject_template` SET `type`=15, `displayId`=12843, `Data0`=5698, `Data1`=20, `Data2`=1, `Data5`=1, `Data6`=1628, `Data8`=1, `Data9`=1, `Data10`=1, `VerifiedBuild`=38134 WHERE `entry`=251513; -- Alliance Battleship
UPDATE `gameobject_template` SET `type`=15, `displayId`=36890, `Data0`=5915, `Data1`=20, `Data2`=1, `Data5`=1, `Data6`=1649, `Data8`=1, `Data9`=1, `Data10`=1, `VerifiedBuild`=38134 WHERE `entry`=254124; -- Horde Battleship
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30894, `ContentTuningId`=866, `VerifiedBuild`=38134 WHERE `entry`=204360; -- Monstrous Clam
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257854; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257853; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257852; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257851; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257850; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257849; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257598; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257597; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257594; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257593; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257582; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257595; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257592; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257579; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257596; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257599; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257580; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257606; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257603; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257590; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257616; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257600; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257610; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257578; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257607; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257588; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257591; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257612; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257611; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257609; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257608; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257605; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257604; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257602; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257601; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257589; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257587; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257586; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257585; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257584; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257583; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257618; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257617; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257615; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257614; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257613; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257581; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `type`=10, `displayId`=14894, `castBarCaption`='Polishing', `size`=0.75, `Data0`=93, `Data3`=1, `Data6`=1, `Data10`=215387, `Data14`=94406, `Data20`=1, `Data23`=1, `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=251195; -- Keg of Armor Polish
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=259137; -- The End Is Coming!
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257712; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257705; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257692; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257747; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257710; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257708; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257707; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257706; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257703; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257702; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257701; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257698; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257696; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257695; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257694; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257693; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257691; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=257688; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=257686; -- Chair
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257746; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257709; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257704; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257700; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257699; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257697; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=257680; -- Chair
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257719; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `type`=10, `displayId`=26597, `castBarCaption`='Eating', `Data0`=93, `Data3`=1, `Data6`=1, `Data10`=215607, `Data13`=1, `Data14`=92973, `Data20`=1, `Data23`=1, `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=251254; -- Grilled Fish
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257815; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257687; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257655; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257636; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257639; -- Anvil
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257799; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257620; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257796; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=259138; -- Goblin Forge
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257825; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257684; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257668; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257777; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257780; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257764; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257748; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257732; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `type`=10, `displayId`=13595, `castBarCaption`='Eating', `Data0`=93, `Data3`=1, `Data6`=1, `Data10`=215607, `Data13`=1, `Data14`=92973, `Data20`=1, `Data23`=1, `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=251255; -- Ribs
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257716; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257633; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257812; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257652; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257681; -- Bubbling Pot
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=251289; -- Tools 1
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257665; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257761; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257745; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257729; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257713; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257809; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257649; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257793; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257822; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=259120; -- Gregg's Cart
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257742; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257726; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257646; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257630; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257678; -- Noodle Cart
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257662; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257806; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257790; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257835; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257774; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257758; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257787; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257771; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257832; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257755; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257739; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257800; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257723; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257643; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257784; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257627; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257675; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257659; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257768; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257819; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257803; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257829; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257752; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=258975; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257765; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257736; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257749; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `type`=10, `displayId`=30219, `castBarCaption`='Eating', `Data0`=93, `Data3`=1, `Data6`=1, `Data10`=215607, `Data13`=1, `Data14`=92973, `Data20`=1, `Data23`=1, `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=251251; -- Baked Fowl
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257720; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257656; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257733; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `type`=10, `displayId`=12775, `castBarCaption`='Eating', `Data0`=93, `Data3`=1, `Data6`=1, `Data10`=215607, `Data13`=1, `Data14`=92973, `Data20`=1, `Data23`=1, `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=251250; -- Baked Fish
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257640; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257672; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257717; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257816; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257653; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257826; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257637; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257813; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257778; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257621; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257685; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257669; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257762; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257797; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257781; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257730; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `type`=10, `displayId`=37165, `castBarCaption`='Enchanting', `size`=0.029999999329447746, `Data0`=93, `Data3`=1, `Data6`=1, `Data10`=215598, `Data13`=1, `Data14`=3006, `Data20`=1, `Data23`=1, `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=255930; -- Sun Sphere
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257810; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257714; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257650; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257634; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257823; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257794; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257682; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257791; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257666; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257679; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257663; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257775; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257759; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257836; -- Horde Battleship
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257743; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257727; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257711; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257807; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257644; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257647; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257631; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257804; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257628; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257676; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257660; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257788; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257772; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257756; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257740; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257833; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257820; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257724; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257785; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257641; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257769; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257673; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257830; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257753; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257737; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257750; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257721; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257817; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257689; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257734; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257801; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257657; -- Forge
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257718; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257654; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=259121; -- Gregg's Rocks
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257638; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257622; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257827; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257670; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257814; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257798; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257795; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257782; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257766; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257779; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257763; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257731; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257715; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257651; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257635; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257619; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257683; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257824; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257667; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257811; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257792; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=259146; -- Goblin Machine
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257834; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257773; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257776; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257760; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257757; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257786; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `type`=3, `displayId`=10513, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data17`=44153, `Data27`=1, `Data30`=69040, `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=255931; -- Cauldron of Mojo
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257744; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257728; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257741; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257648; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257770; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257632; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257664; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257808; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257754; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257725; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=254942; -- Horde Battleship
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257738; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257821; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `type`=10, `displayId`=34807, `castBarCaption`='Eating', `Data0`=93, `Data3`=1, `Data6`=1, `Data10`=215607, `Data13`=1, `Data14`=92973, `Data20`=1, `Data23`=1, `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=251252; -- Dumplings
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257645; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257818; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257629; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257722; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257805; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257831; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `type`=10, `displayId`=34808, `castBarCaption`='Eating', `Data0`=93, `Data3`=1, `Data6`=1, `Data10`=215607, `Data13`=1, `Data14`=92973, `Data20`=1, `Data23`=1, `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=251253; -- Fried Rice
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257677; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257661; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257789; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257690; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257642; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257626; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257623; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=259136; -- Spear Wall
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257802; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257671; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257674; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257658; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257783; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=258974; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257767; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257751; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257828; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=259122; -- Spears
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=38134 WHERE `entry`=257735; -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213121; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213697; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213670; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213721; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213675; -- Tongs
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213713; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213689; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214728; -- Mage
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213989; -- Monk
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213726; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213718; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213667; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213984; -- Rogue
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213710; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213677; -- Hammer
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213694; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214727; -- Warrior
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213686; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213115; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213142; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213728; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213669; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213683; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213680; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278347; -- Warchief's Command Board
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213723; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213707; -- Bar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213699; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214176; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213691; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213133; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215128; -- Collision PC Size
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213991; -- Priest
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213720; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213725; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213712; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213704; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213986; -- Deathknight
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=222778; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213696; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213717; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213688; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213709; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213727; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213706; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213701; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213693; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213682; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213685; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213141; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215127; -- Portal to Orgrimmar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213122; -- Hammer
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213716; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214234; -- Guild Vault
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213722; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213719; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213714; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213676; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213698; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213690; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213711; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213703; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213668; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214729; -- Warlock
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213695; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213687; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213143; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213987; -- Druid
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213132; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213990; -- Paladin
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213985; -- Shaman
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213116; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213724; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213702; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213708; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213681; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213692; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213715; -- Banner
UPDATE `gameobject_template` SET `type`=50, `IconName`='', `Data0`=2860, `Data1`=52249, `Data3`=0, `Data4`=100, `Data5`=100, `Data7`=0, `Data12`=681, `Data13`=1, `Data14`=170540, `Data18`=1, `Data19`=0, `Data23`=0, `Data24`=0, `VerifiedBuild`=38134 WHERE `entry`=228572; -- Fireweed
UPDATE `gameobject_template` SET `name`='Huge Fire', `VerifiedBuild`=38134 WHERE `entry`=232524; -- Huge Fire
UPDATE `gameobject_template` SET `name`='Small Fire', `VerifiedBuild`=38134 WHERE `entry`=232521; -- Small Fire
UPDATE `gameobject_template` SET `name`='Large Fire', `VerifiedBuild`=38134 WHERE `entry`=232513; -- Large Fire
UPDATE `gameobject_template` SET `ContentTuningId`=67, `VerifiedBuild`=38134 WHERE `entry`=231910; -- Firebomb Plunger
UPDATE `gameobject_template` SET `name`='Goblin Shelf', `VerifiedBuild`=38134 WHERE `entry`=234475; -- Goblin Shelf
UPDATE `gameobject_template` SET `type`=3, `Data17`=0, `Data19`=2, `ContentTuningId`=67, `VerifiedBuild`=38134 WHERE `entry`=234473; -- Campaign Contributions
UPDATE `gameobject_template` SET `name`='Gold Pile', `VerifiedBuild`=38134 WHERE `entry`=233716; -- Gold Pile


UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=58595 AND `Idx`=0); -- Burning Blade Stash
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=204360 AND `Idx`=0); -- Monstrous Clam


DELETE FROM `playerchoice_response` WHERE (`ChoiceId`=342 AND `ResponseId`=910 AND `Index`=2) OR (`ChoiceId`=342 AND `ResponseId`=911 AND `Index`=1);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `ResponseIdentifier`, `Index`, `ChoiceArtFileId`, `Flags`, `WidgetSetId`, `UiTextureAtlasElementID`, `SoundKitId`, `GroupId`, `Header`, `Subheader`, `ButtonTooltip`, `Answer`, `Description`, `Confirmation`, `RewardQuestID`, `UiTextureKitID`, `VerifiedBuild`) VALUES
(342, 910, 1766, 2, 1851144, 0, 0, 0, 0, 0, 'Spires of Arak', '', '', 'Assist the Outcasts', 'The arakkoa outcasts are fleeing the Spires of Arak and heading into Talador, and we must know why.\n\nAssist the outcasts, find out why they are fleeing, and perhaps we will gain valuable information to aid us in our fight against the Iron Horde.', '', 0, 0, 38134),
(342, 911, 1765, 1, 1851142, 0, 0, 0, 0, 0, 'Nagrand', '', '', 'Travel to Nagrand', 'The Burning Blade and Warsong clans reside in Nagrand. They must be brought to justice.\n\nShow these clans that they are on the wrong side of this conflict.', '', 0, 0, 38134);

UPDATE `playerchoice_response` SET `ResponseIdentifier`=1764, `Header`='Broken Shore', `Answer`='Fight the Legion', `Description`='The Burning Legion has returned to Azeroth!' WHERE (`ChoiceId`=342 AND `ResponseId`=1429 AND `Index`=0);


UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=28026; -- 28026
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23538; -- 23538
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23580; -- 23580
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=24424; -- 24424
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=24430; -- 24430
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=24994; -- 24994
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23891; -- 23891
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23875; -- 23875
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23846; -- 23846
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=27278; -- 27278
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=30383; -- 30383
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=29496; -- 29496
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=24099; -- 24099
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=24737; -- 24737

