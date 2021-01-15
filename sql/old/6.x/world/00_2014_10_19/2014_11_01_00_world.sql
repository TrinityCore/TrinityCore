ALTER TABLE `areatrigger_teleport` CHANGE `id` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `areatrigger_teleport` CHANGE `name` `Name` TEXT;
ALTER TABLE `areatrigger_teleport` DROP COLUMN `target_map`;
ALTER TABLE `areatrigger_teleport` DROP COLUMN `target_position_x`;
ALTER TABLE `areatrigger_teleport` DROP COLUMN `target_position_y`;
ALTER TABLE `areatrigger_teleport` DROP COLUMN `target_position_z`;
ALTER TABLE `areatrigger_teleport` DROP COLUMN `target_orientation`;
ALTER TABLE `areatrigger_teleport` DROP COLUMN `VerifiedBuild`;
ALTER TABLE `areatrigger_teleport` ADD COLUMN `PortLocID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`;

DELETE FROM `areatrigger_teleport` WHERE `id` IN (1468, 4561, 4562, 5051, 5079, 5273, 5879, 5880, 5931, 5937);

UPDATE `areatrigger_teleport` SET `PortLocID`=3597 WHERE `id`=45;   -- Scarlet Monastery Entrance Target 01
UPDATE `areatrigger_teleport` SET `PortLocID`=3598 WHERE `id`=78;   -- Deadmines Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3599 WHERE `id`=101;  -- Stormwind Jail Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3600 WHERE `id`=109;  -- Stormwind High Prison Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3601 WHERE `id`=119;  -- Deadmines Exit Front Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3602 WHERE `id`=145;  -- Shadowfang Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3603 WHERE `id`=194;  -- Shadowfang Bridge Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3604 WHERE `id`=226;  -- Wailing Caverns Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3605 WHERE `id`=228;  -- Wailing Cavern Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3606 WHERE `id`=242;  -- Razorfen Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3607 WHERE `id`=244;  -- Razorfen Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3608 WHERE `id`=257;  -- Blackfathom Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3609 WHERE `id`=259;  -- Blackfathom Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3610 WHERE `id`=286;  -- Uldaman Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3611 WHERE `id`=288;  -- Uldaman Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3612, `name`='Gnomeregon Exit Target' WHERE `id`=322; -- Gnomeregan Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3613 WHERE `id`=324;  -- Gnomeregan Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3614 WHERE `id`=442;  -- Razorfen Downs Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3615 WHERE `id`=444;  -- Razorfen Downs Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3616 WHERE `id`=446;  -- Sunken Temple Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3617 WHERE `id`=448;  -- Sunken Temple Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3618 WHERE `id`=503;  -- Stormwind Low Prison Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3619 WHERE `id`=523;  -- Gnomeregan Entrance 02 Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3620, `name`='Gnomeregon Exit 02 Target' WHERE `id`=525; -- Gnomeregan Exit 02 Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3621 WHERE `id`=527;  -- Darnassus Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3622 WHERE `id`=542;  -- Darnassus Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3623 WHERE `id`=602;  -- Scarlet Monastery Exit Target 01
UPDATE `areatrigger_teleport` SET `PortLocID`=3624 WHERE `id`=604;  -- Scarlet Monastery Exit Target 02
UPDATE `areatrigger_teleport` SET `PortLocID`=3625 WHERE `id`=606;  -- Scarlet Monastery Exit Target 03
UPDATE `areatrigger_teleport` SET `PortLocID`=3626 WHERE `id`=608;  -- Scarlet Monastery Exit Target 04
UPDATE `areatrigger_teleport` SET `PortLocID`=3627 WHERE `id`=610;  -- Scarlet Monastery Entrance Target 02
UPDATE `areatrigger_teleport` SET `PortLocID`=3628 WHERE `id`=612;  -- Scarlet Monastery Entrance Target 03
UPDATE `areatrigger_teleport` SET `PortLocID`=3629 WHERE `id`=614;  -- Scarlet Monastery Entrance Target 04
UPDATE `areatrigger_teleport` SET `PortLocID`=3630 WHERE `id`=702;  -- Stormwind - Mage Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3631 WHERE `id`=704;  -- Stormwind - Mage Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3632 WHERE `id`=882;  -- Uldaman Exit Target Rear
UPDATE `areatrigger_teleport` SET `PortLocID`=3633 WHERE `id`=902;  -- Uldaman Entrance Target Rear
UPDATE `areatrigger_teleport` SET `PortLocID`=3634, `name`='Zul''Farrakk Exit Target' WHERE `id`=922; -- Zul'Farrak Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3635 WHERE `id`=924;  -- Zul''Farrak Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3636 WHERE `id`=943;  -- Thousand Needles - Test of Faith (Target)
UPDATE `areatrigger_teleport` SET `PortLocID`=3639 WHERE `id`=1064; -- Onyxia''s Lair Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3643 WHERE `id`=1466; -- Blackrock Depths Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3646 WHERE `id`=1472; -- Blackrock Depths Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3648 WHERE `id`=2166; -- Ironforge - Tram Exit Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3649 WHERE `id`=2171; -- Stormwind - Tram Exit Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3650 WHERE `id`=2173; -- Stormwind - Tram Entrance Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3651 WHERE `id`=2175; -- Ironforge - Tram Entrance Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3652 WHERE `id`=2214; -- Stratholme - Back Entrance Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3653 WHERE `id`=2216; -- Stratholme - Front Right Entrance Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3654 WHERE `id`=2217; -- Stratholme - Front Left Entrance Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3655 WHERE `id`=2221; -- Stratholme - Back Exit Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3656 WHERE `id`=2226; -- OrgrimmarInstance Exit Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3657 WHERE `id`=2230; -- OrgrimmarInstance Entrance Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3658 WHERE `id`=2406; -- Shadowfang - South Fall Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3659 WHERE `id`=2407; -- Shadowfang - South Fall Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3660 WHERE `id`=2408; -- Shadowfang Front Fall Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3661 WHERE `id`=2409; -- Shadowfang Front Fall Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3662 WHERE `id`=2410; -- Shadowfang - North Fall Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3663 WHERE `id`=2411; -- Shadowfang - North Fall Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3666 WHERE `id`=2530; -- Orgrimmar - Barracks Exit Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3667 WHERE `id`=2534; -- Stormwind - Barracks Exit Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3668 WHERE `id`=2547; -- Scholomance - Exit Porch Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3669 WHERE `id`=2548; -- Scholomance - Exit Porch Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3670 WHERE `id`=2549; -- Scholomance - Exit Porch Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3671, `name`='Scholomance 5.0 - Entrance target' WHERE `id`=2567; -- Scholomance - Entrance target
UPDATE `areatrigger_teleport` SET `PortLocID`=3672 WHERE `id`=2568; -- Scholomance - Stairs Exit Target 001
UPDATE `areatrigger_teleport` SET `PortLocID`=3673 WHERE `id`=2606; -- Alterac Valley - Horde Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3674 WHERE `id`=2608; -- Alterac Valley - Alliance Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3675 WHERE `id`=2848; -- Onyxia''s Lair Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3676 WHERE `id`=2886; -- Molten Core Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3677 WHERE `id`=2890; -- Molten Core Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3678 WHERE `id`=3126; -- Maraudon - Purple Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3679 WHERE `id`=3131; -- Maraudon - Orange Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3680 WHERE `id`=3133; -- Maraudon - Orange Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3681 WHERE `id`=3134; -- Maraudon - Purple Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3682 WHERE `id`=3183; -- Dire Maul - East Entrance Target 01
UPDATE `areatrigger_teleport` SET `PortLocID`=3683 WHERE `id`=3184; -- Dire Maul - East Entrance Target 02
UPDATE `areatrigger_teleport` SET `PortLocID`=3684 WHERE `id`=3185; -- Dire Maul - East Entrance Target 03
UPDATE `areatrigger_teleport` SET `PortLocID`=3685 WHERE `id`=3186; -- Dire Maul - West Entrance Target 01
UPDATE `areatrigger_teleport` SET `PortLocID`=3686 WHERE `id`=3187; -- Dire Maul - West Entrance Target 02
UPDATE `areatrigger_teleport` SET `PortLocID`=3687 WHERE `id`=3189; -- Dire Maul - North Entrance Target 02
UPDATE `areatrigger_teleport` SET `PortLocID`=3688 WHERE `id`=3190; -- Dire Maul - West Exit Target 01
UPDATE `areatrigger_teleport` SET `PortLocID`=3689 WHERE `id`=3191; -- Dire Maul - West Exit Target 02
UPDATE `areatrigger_teleport` SET `PortLocID`=3690 WHERE `id`=3193; -- Dire Maul - North Exit Target 02
UPDATE `areatrigger_teleport` SET `PortLocID`=3691 WHERE `id`=3194; -- Dire Maul - East Exit Target 01
UPDATE `areatrigger_teleport` SET `PortLocID`=3692 WHERE `id`=3195; -- Dire Maul - East Exit Target 02
UPDATE `areatrigger_teleport` SET `PortLocID`=3693 WHERE `id`=3196; -- Dire Maul - East Exit Target 03
UPDATE `areatrigger_teleport` SET `PortLocID`=3694 WHERE `id`=3197; -- Dire Maul - East Exit Target 04
UPDATE `areatrigger_teleport` SET `PortLocID`=3695 WHERE `id`=3528; -- Molten Core Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3696 WHERE `id`=3529; -- Molten Core Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3700 WHERE `id`=3726; -- Blackwing Lair - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3701 WHERE `id`=1470; -- Blackrock Spire Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3701 WHERE `id`=3728; -- Blackrock Spire Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3703 WHERE `id`=3948; -- Arathi Highlands - Arathi Basin Exit Target - Alliance
UPDATE `areatrigger_teleport` SET `PortLocID`=3704 WHERE `id`=3949; -- Arathi Highlands - Arathi Basin Exit Target - Horde
UPDATE `areatrigger_teleport` SET `PortLocID`=3707 WHERE `id`=4006; -- Ahn''Qiraj Ruins - Outbound Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3708 WHERE `id`=4008; -- Ahn''Qiraj Ruins - Inbound Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3709 WHERE `id`=4010; -- Ahn''Qiraj Temple - Inbound Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3710 WHERE `id`=4012; -- Ahn''Qiraj Temple - Outbound Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3712 WHERE `id`=4131; -- Karazhan - Front Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3713 WHERE `id`=4135; -- Karazhan - Upper Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3714 WHERE `id`=4145; -- Hellfire Military - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3715 WHERE `id`=4147; -- Hellfire Demon - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3716 WHERE `id`=4149; -- Hellfire Raid - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3717 WHERE `id`=4150; -- Hellfire Ramparts - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3718 WHERE `id`=4151; -- Hellfire Military - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3719 WHERE `id`=4152; -- Hellfire Demon - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3720 WHERE `id`=4153; -- Hellfire Raid - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3723 WHERE `id`=4233; -- Eversong Woods - Duskwither UP Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3724 WHERE `id`=4267; -- Eversong Woods - Duskwither DOWN Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3725 WHERE `id`=4297; -- Hellfire Ramparts - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3726 WHERE `id`=4304; -- Hellfire Ramparts - Omor Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3727 WHERE `id`=4311; -- CoT - Hyjal - Human Base - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3728 WHERE `id`=4312; -- CoT - Hyjal - Orc Base - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3729 WHERE `id`=4313; -- CoT - Hyjal - Night Elf Base - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3730 WHERE `id`=4319; -- CoT - Hyjal - Entrance - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3731 WHERE `id`=4320; -- CoT - Black Morass - Entrance - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3732 WHERE `id`=4321; -- CoT - Hillsbrad - Entrance - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3733 WHERE `id`=4322; -- CoT - Black Morass - Exit - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3734 WHERE `id`=4323; -- CoT - Hyjal - Exit - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3735 WHERE `id`=4324; -- CoT - Hillsbrad - Exit - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3736 WHERE `id`=4352; -- Dark Portal - E. Kingdoms Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3737 WHERE `id`=4354; -- Dark Portal - Outland Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3738 WHERE `id`=4363; -- Coilfang Marsh - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3739 WHERE `id`=4364; -- Coilfang Pumping - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3740 WHERE `id`=4365; -- Coilfang Draenei - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3741 WHERE `id`=4366; -- Coilfang Pumping - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3742 WHERE `id`=4367; -- Coilfang Marsh - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3743 WHERE `id`=4379; -- Coilfang Draenei - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3744 WHERE `id`=4386; -- Eastern Plaguelands - From Ghostlands Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3745 WHERE `id`=4397; -- Auchindoun Shadow - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3746 WHERE `id`=4399; -- Auchindoun Arakkoa - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3747 WHERE `id`=4401; -- Auchindoun Etherial - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3748 WHERE `id`=4403; -- Auchindoun Draenei - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3749 WHERE `id`=4404; -- Auchindoun Draenei - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3750 WHERE `id`=4405; -- Auchindoun Etherial - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3751 WHERE `id`=4406; -- Auchindoun Arakkoa - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3752 WHERE `id`=4407; -- Auchindoun Shadow - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3753 WHERE `id`=4409; -- Ghostlands - EPL Return Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3754 WHERE `id`=4416; -- Coilfang Raid - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3755 WHERE `id`=4418; -- Coilfang Raid - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3756 WHERE `id`=4436; -- Karazhan - Front Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3761 WHERE `id`=4455; -- Tempest Keep - Arcane Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3762 WHERE `id`=4457; -- Tempest Keep - Raid Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3763 WHERE `id`=4459; -- Tempest Keep - Atrium Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3764 WHERE `id`=4461; -- Tempest Keep - Factory Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3765 WHERE `id`=4467; -- Tempest Keep - Atrium Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3766 WHERE `id`=4468; -- Tempest Keep - Arcane Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3767 WHERE `id`=4469; -- Tempest Keep - Factory Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3768 WHERE `id`=4470; -- Tempest Keep - Raid Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3770 WHERE `id`=4487; -- CoT - Hyjal - Exit - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3771 WHERE `id`=4520; -- Karazhan - Upper Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3774 WHERE `id`=4534; -- Gruul''s Lair - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3775 WHERE `id`=4535; -- Gruul''s Lair - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3780 WHERE `id`=4598; -- Black Temple - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3781 WHERE `id`=4612; -- Tempest Keep - Atrium Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3782 WHERE `id`=4614; -- Tempest Keep - Factory Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3783 WHERE `id`=4619; -- Black Temple - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3786 WHERE `id`=4738; -- Zul''Aman - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3787 WHERE `id`=4739; -- Zul''Aman - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3788 WHERE `id`=4741; -- Utgarde Keep - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3789 WHERE `id`=4743; -- Utgarde Pinnacle - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3790 WHERE `id`=4745; -- Utgarde Keep - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3791 WHERE `id`=4747; -- Utgarde Pinnacle - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3793 WHERE `id`=4885; -- Magisters'' Terrace - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3794 WHERE `id`=4887; -- Magisters'' Terrace - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3795 WHERE `id`=4889; -- Sunwell Raid - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3796 WHERE `id`=4891; -- Sunwell Raid - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3799 WHERE `id`=4917; -- Arena - Nagrand - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3800, `name`='Arena - Bladesedge - Teleport Target - Game On 1' WHERE `id`=4919; -- Arena - Bladesedge - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3801, `name`='Arena - Bladesedge - Teleport Target - Game On 2' WHERE `id`=4921; -- Arena - Bladesedge - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3802, `name`='Arena - Bladesedge - Teleport Target - Game On 3' WHERE `id`=4922; -- Arena - Bladesedge - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3803, `name`='Arena - Bladesedge - Teleport Target - Game On 5' WHERE `id`=4923; -- Arena - Bladesedge - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3804, `name`='Arena - Bladesedge - Teleport Target - Game On 4' WHERE `id`=4924; -- Arena - Bladesedge - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3805, `name`='Arena - Bladesedge - Teleport Target - Game On 7' WHERE `id`=4925; -- Arena - Bladesedge - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3806 WHERE `id`=4927; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3807 WHERE `id`=4928; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3808 WHERE `id`=4929; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3809 WHERE `id`=4930; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3810 WHERE `id`=4931; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3811 WHERE `id`=4932; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3812 WHERE `id`=4933; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3813 WHERE `id`=4934; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3814 WHERE `id`=4935; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3815 WHERE `id`=4936; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3816 WHERE `id`=4941; -- Arena - Undercity - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3817, `name`='Arena - Bladesedge - Teleport Target - Game On 6' WHERE `id`=4944; -- Arena - Bladesedge - Teleport Target - Game On
UPDATE `areatrigger_teleport` SET `PortLocID`=3819 WHERE `id`=4981; -- The Nexus - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3820 WHERE `id`=4983; -- The Nexus - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3821 WHERE `id`=4998; -- Drak''Tharon - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3822 WHERE `id`=5000; -- Drak''Tharon - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3825 WHERE `id`=5010; -- Halls of Stone - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3826 WHERE `id`=5012; -- Halls of Stone - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3835 WHERE `id`=5091; -- Ulduar 80 - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3836 WHERE `id`=5093; -- Ulduar 80 - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3837 WHERE `id`=5113; -- Azjol-Nerub Back Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3838 WHERE `id`=5115; -- Azjol-Nerub Front Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3839 WHERE `id`=5117; -- Azjol-Nerub Front Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3840 WHERE `id`=5127; -- Ebon Hold (E.K.) Top Return Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3841 WHERE `id`=5128; -- Ebon Hold (E.K.) Top West Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3842 WHERE `id`=5129; -- Ebon Hold (E.K.) Top Return Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3843 WHERE `id`=5130; -- Ebon Hold (E.K.) Top South Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3844 WHERE `id`=5131; -- Ebon Hold (E.K.) Top Return Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3845 WHERE `id`=5132; -- Ebon Hold (E.K.) Top North Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3846 WHERE `id`=5133; -- Ebon Hold (E.K.) Top Return Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3847 WHERE `id`=5134; -- Ebon Hold (E.K.) Top East Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3848 WHERE `id`=5135; -- Ebon Hold (E.K.) Middle -> Bottom Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3849 WHERE `id`=5136; -- Ebon Hold (E.K.) Middle -> Bottom Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3850 WHERE `id`=5137; -- Ebon Hold (E.K.) Bottom -> Middle Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3851 WHERE `id`=5138; -- Ebon Hold (E.K.) Bottom -> Ground Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3852 WHERE `id`=5181; -- CoT Stratholme - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3853 WHERE `id`=5150; -- CoT Stratholme - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3854 WHERE `id`=5148; -- CoT Stratholme - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3857 WHERE `id`=5191; -- Naxxramas - Entrance Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3858 WHERE `id`=5192; -- Naxxramas - Entrance Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3859 WHERE `id`=5193; -- Naxxramas - Entrance Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3860 WHERE `id`=5194; -- Naxxramas - Entrance Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3861 WHERE `id`=5196; -- Naxxramas - Exit Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3862 WHERE `id`=5197; -- Naxxramas - Exit Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3863 WHERE `id`=5198; -- Naxxramas - Exit Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3864 WHERE `id`=5199; -- Naxxramas - Exit Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3865, `name`='Gundrak - Entrace Target A (Mammoth)' WHERE `id`=5205; -- Gundrak - Entrance Target A (Mammoth)
UPDATE `areatrigger_teleport` SET `PortLocID`=3866, `name`='Gundrak - Entrace Target B (Snake)' WHERE `id`=5206; -- Gundrak - Entrance Target B (Snake)
UPDATE `areatrigger_teleport` SET `PortLocID`=3867 WHERE `id`=5209; -- Violet Hold - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3868 WHERE `id`=5211; -- Violet Hold - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3869 WHERE `id`=5213; -- Lower City - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3870 WHERE `id`=5215; -- Lower City - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3871 WHERE `id`=5231; -- Gundrak - Exit Target A (Mammoth)
UPDATE `areatrigger_teleport` SET `PortLocID`=3872 WHERE `id`=5233; -- Gundrak - Exit Target B (Snake)
UPDATE `areatrigger_teleport` SET `PortLocID`=3873, `name`='Azjol-Nerub Back Exit Target' WHERE `id`=5235; -- Ahn'Kahet (exit)
UPDATE `areatrigger_teleport` SET `PortLocID`=3874 WHERE `id`=5241; -- CoA Black - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3875 WHERE `id`=5243; -- CoA Black - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3876 WHERE `id`=5246; -- Nexus 80 - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3878 WHERE `id`=5258; -- Wintergrasp Raid - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3879 WHERE `id`=5262; -- Wintergrasp Raid - Teleport Target - Exit
UPDATE `areatrigger_teleport` SET `PortLocID`=3880 WHERE `id`=5276; -- Gundrak - Exit Target A (Mammoth)
UPDATE `areatrigger_teleport` SET `PortLocID`=3881 WHERE `id`=5277; -- Gundrak - Exit Target B (Snake)
UPDATE `areatrigger_teleport` SET `PortLocID`=3882 WHERE `id`=5290; -- Eye of Eternity - Port In Loc
UPDATE `areatrigger_teleport` SET `PortLocID`=3889 WHERE `id`=5326; -- Arena - Dalaran Arena - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3890 WHERE `id`=5328; -- Arena - Dalaran Arena - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3891 WHERE `id`=5329; -- Arena - Dalaran Arena - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3892 WHERE `id`=5330; -- Arena - Dalaran Arena - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3893 WHERE `id`=5331; -- Arena - Dalaran Arena - Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3903 WHERE `id`=5379; -- Ulduar Raid - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3904 WHERE `id`=5381; -- Ulduar Raid - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3906 WHERE `id`=5447; -- Arena - Orgrimmar - Teleport Target 3
UPDATE `areatrigger_teleport` SET `PortLocID`=3914 WHERE `id`=5503; -- Argent Raid - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3915 WHERE `id`=5505; -- Argent Dungeon - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3916 WHERE `id`=5508; -- Argent Raid - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3917 WHERE `id`=5510; -- Argent Dungeon - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3920 WHERE `id`=5635; -- Icecrown Dungeon - Forge of Souls - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3921 WHERE `id`=5636; -- Icecrown Dungeon - Halls of Reflection - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3922 WHERE `id`=5637; -- Icecrown Dungeon - Pit of Saron - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3923 WHERE `id`=5642; -- Icecrown Dungeon - Forge of Souls - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3924 WHERE `id`=5643; -- Icecrown Dungeon - Pit of Saron - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3925 WHERE `id`=5646; -- Icecrown Dungeon - Halls of Reflection - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3928 WHERE `id`=5668; -- Icecrown Raid - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3929 WHERE `id`=5670; -- Icecrown Raid - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3932 WHERE `id`=5683; -- Icecrown Dungeon - Halls of Reflection - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3933 WHERE `id`=5688; -- Icecrown Dungeon - Pit of Saron - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3937, `name`='Icecrown Dungeon - Halls of Reflection - Player Bounce Target' WHERE `id`=5740; -- Halls of Reflection (The Impenetrable Door)
-- UPDATE `areatrigger_teleport` SET `PortLocID`=, `name`='' WHERE `id`=; -- 
UPDATE `areatrigger_teleport` SET `PortLocID`=3940 WHERE `id`=5869; -- Ruby Sanctum - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3941 WHERE `id`=5872; -- Ruby Sanctum - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3942 WHERE `id`=5893; -- Hyjal - Teleport from Seat of the Prophets
UPDATE `areatrigger_teleport` SET `PortLocID`=3943 WHERE `id`=5895; -- Hyjal - Teleport From Sulfuron Spire
UPDATE `areatrigger_teleport` SET `PortLocID`=3950 WHERE `id`=5926; -- The Lost Isles - Volcanoth''s Lair - Teleport Target - Phase 8+
UPDATE `areatrigger_teleport` SET `PortLocID`=3953 WHERE `id`=6011; -- Blackrock Caverns - Exit Target (in Eastern Kingdoms)
UPDATE `areatrigger_teleport` SET `PortLocID`=3954 WHERE `id`=6197; -- Vashj''ir - Throne of Tides Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3955 WHERE `id`=6108; -- Blackrock Caverns - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3956 WHERE `id`=6177; -- Grim Batol Dungeon - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3957 WHERE `id`=6179; -- Grim Batol Dungeon - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3958 WHERE `id`=6194; -- Deepholm - Stonecore Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3959 WHERE `id`=6196; -- Stonecore - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3960 WHERE `id`=6073; -- Vashj''ir - Throne of Tides Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3961 WHERE `id`=6201; -- Throne of Tides - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3962 WHERE `id`=6210; -- Stratholme - Front Right Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3963 WHERE `id`=6211; -- Stratholme - Front Left Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3964 WHERE `id`=6321; -- Badlands 4.x - Cliff Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3965 WHERE `id`=6322; -- Badlands 4.x - Dock Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3966 WHERE `id`=6341; -- Twilight Bastion - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3967 WHERE `id`=6354; -- Twilight Bastion - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3970 WHERE `id`=6485; -- Halls of Origination - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3971 WHERE `id`=6487; -- Halls of Origination - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3972 WHERE `id`=6488; -- Lost City of the Tol''vir - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3973 WHERE `id`=6580; -- Blackwing Descent - Exit Target (in Eastern Kingdoms)
UPDATE `areatrigger_teleport` SET `PortLocID`=3974 WHERE `id`=6581; -- Blackwing Descent - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3975 WHERE `id`=6610; -- The Vortex Pinnacle - Exit Target (in Kalimdor)
UPDATE `areatrigger_teleport` SET `PortLocID`=3976 WHERE `id`=6612; -- The Vortex Pinnacle - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3977 WHERE `id`=6618; -- Baradin Hold - Exit Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3978 WHERE `id`=6620; -- Lost City of Tol''vir - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3989 WHERE `id`=6664; -- Baradin Hold - Entrance Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3990 WHERE `id`=6672; -- Skywall Raid - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3991 WHERE `id`=6673; -- Uldum - Skywall Raid Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3995 WHERE `id`=6769; -- Zul''Gurub 4.1 - Exit Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3996 WHERE `id`=6775; -- Zul''Gurub 4.1 - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3998 WHERE `id`=6864; -- Firelands - Entrance Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=3999 WHERE `id`=6866; -- Firelands - Exit Teleport Target
UPDATE `areatrigger_teleport` SET `PortLocID`=4003 WHERE `id`=7151; -- CoT 4.3 - Well of Eternity - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=4004 WHERE `id`=7152; -- CoT 4.3 - End Time - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=4005 WHERE `id`=7154; -- CoT 4.3 - Hour of Twilight - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=4006 WHERE `id`=7155; -- CoT 4.3 - Dragon Soul - Entrance Target
UPDATE `areatrigger_teleport` SET `PortLocID`=4007 WHERE `id`=7161; -- CoT 4.3 - Well of Eternity - Exit Target (In Kalimdor)
UPDATE `areatrigger_teleport` SET `PortLocID`=4008 WHERE `id`=7162; -- CoT 4.3 - End Time - Exit Target (In Kalimdor)
UPDATE `areatrigger_teleport` SET `PortLocID`=4009 WHERE `id`=7163; -- CoT 4.3 - Hour of Twilight - Exit Target (In Kalimdor)
UPDATE `areatrigger_teleport` SET `PortLocID`=4010 WHERE `id`=7164; -- CoT 4.3 - Dragon Soul - Exit Target (In Kalimdor)
UPDATE `areatrigger_teleport` SET `PortLocID`=4292 WHERE `id`=121; -- Deadmines Rear Exit Target
