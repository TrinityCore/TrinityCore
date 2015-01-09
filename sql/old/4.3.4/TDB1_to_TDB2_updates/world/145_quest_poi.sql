DELETE FROM `quest_poi` WHERE `questid` IN (25900, 25908, 25907, 25909, 25916, 25917, 25919, 25918, 25920, 25921, 25922, 25536, 25535);
INSERT INTO `quest_poi` (`questid`, `id`, `objIndex`, `mapid`, `WorldMapAreaId`, `FloorId`, `unk3`, `unk4`) VALUES
(25900, 0, -1, 0, 610, 0, 0, 1), -- Making Contact
(25900, 1, 16, 0, 610, 0, 0, 1), -- Making Contact
(25908, 5, 0, 0, 615, 0, 0, 3), -- Stick it to Them
(25908, 6, -1, 0, 615, 0, 0, 3), -- Stick it to Them
(25908, 7, 1, 0, 615, 0, 0, 3), -- Stick it to Them
(25907, 0, -1, 0, 615, 0, 0, 1), -- Slave Labor
(25907, 1, 0, 0, 615, 0, 0, 1), -- Slave Labor
(25907, 2, 0, 0, 615, 0, 0, 1), -- Slave Labor
(25907, 3, 0, 0, 615, 0, 0, 1), -- Slave Labor
(25907, 4, 0, 0, 615, 0, 0, 1), -- Slave Labor
(25907, 5, 0, 0, 615, 0, 0, 1), -- Slave Labor
(25909, 0, -1, 0, 610, 0, 0, 1), -- Capture the Crab
(25909, 1, 4, 0, 610, 0, 0, 1), -- Capture the Crab
(25909, 2, 4, 0, 610, 0, 0, 1), -- Capture the Crab
(25916, 0, -1, 0, 610, 0, 0, 1), -- Breaking Through
(25916, 1, 16, 0, 610, 0, 0, 1), -- Breaking Through
(25917, 0, -1, 0, 615, 0, 0, 1), -- We Are Not Alone
(25919, 0, 0, 0, 615, 0, 0, 1), -- Body Blows
(25919, 1, -1, 0, 615, 0, 0, 1), -- Body Blows
(25918, 0, 4, 0, 615, 0, 0, 1), -- Hopelessly Gearless
(25918, 1, -1, 0, 615, 0, 0, 1), -- Hopelessly Gearless
(25920, 0, -1, 0, 615, 0, 0, 1), -- Still Valuable
(25920, 1, 4, 0, 615, 0, 0, 1), -- Still Valuable
(25921, 1, -1, 0, 615, 0, 0, 3), -- Overseer Idra'kess
(25921, 2, 0, 0, 615, 0, 0, 3), -- Overseer Idra'kess
(25922, 0, 0, 0, 610, 0, 0, 1), -- Waking the Beast
(25922, 1, 1, 0, 610, 0, 0, 1), -- Waking the Beast
(25922, 2, 0, 0, 615, 0, 0, 1), -- Waking the Beast
(25922, 3, 1, 0, 615, 0, 0, 1), -- Waking the Beast
(25922, 4, -1, 0, 615, 0, 0, 7), -- Waking the Beast
(25536, 0, 0, 0, 615, 0, 0, 1), -- Cold Welcome
(25536, 1, -1, 0, 615, 0, 0, 3), -- Cold Welcome
(25535, 0, -1, 0, 615, 0, 0, 1); -- A Powerful Need To Eat


DELETE FROM `quest_poi_points` WHERE (`questId`=25900 AND `id`=0) OR (`questId`=25900 AND `id`=1) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=5) OR (`questId`=25908 AND `id`=6) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25908 AND `id`=7) OR (`questId`=25907 AND `id`=0) OR (`questId`=25907 AND `id`=1) OR (`questId`=25907 AND `id`=1) OR (`questId`=25907 AND `id`=1) OR (`questId`=25907 AND `id`=1) OR (`questId`=25907 AND `id`=1) OR (`questId`=25907 AND `id`=2) OR (`questId`=25907 AND `id`=2) OR (`questId`=25907 AND `id`=2) OR (`questId`=25907 AND `id`=2) OR (`questId`=25907 AND `id`=2) OR (`questId`=25907 AND `id`=2) OR (`questId`=25907 AND `id`=2) OR (`questId`=25907 AND `id`=2) OR (`questId`=25907 AND `id`=3) OR (`questId`=25907 AND `id`=3) OR (`questId`=25907 AND `id`=3) OR (`questId`=25907 AND `id`=3) OR (`questId`=25907 AND `id`=3) OR (`questId`=25907 AND `id`=3) OR (`questId`=25907 AND `id`=3) OR (`questId`=25907 AND `id`=4) OR (`questId`=25907 AND `id`=4) OR (`questId`=25907 AND `id`=4) OR (`questId`=25907 AND `id`=4) OR (`questId`=25907 AND `id`=4) OR (`questId`=25907 AND `id`=4) OR (`questId`=25907 AND `id`=4) OR (`questId`=25907 AND `id`=4) OR (`questId`=25907 AND `id`=5) OR (`questId`=25907 AND `id`=5) OR (`questId`=25907 AND `id`=5) OR (`questId`=25907 AND `id`=5) OR (`questId`=25907 AND `id`=5) OR (`questId`=25907 AND `id`=5) OR (`questId`=25907 AND `id`=5) OR (`questId`=25907 AND `id`=5) OR (`questId`=25909 AND `id`=0) OR (`questId`=25909 AND `id`=1) OR (`questId`=25909 AND `id`=1) OR (`questId`=25909 AND `id`=1) OR (`questId`=25909 AND `id`=1) OR (`questId`=25909 AND `id`=2) OR (`questId`=25909 AND `id`=2) OR (`questId`=25909 AND `id`=2) OR (`questId`=25909 AND `id`=2) OR (`questId`=25916 AND `id`=0) OR (`questId`=25916 AND `id`=1) OR (`questId`=25917 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=0) OR (`questId`=25919 AND `id`=1) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=0) OR (`questId`=25918 AND `id`=1) OR (`questId`=25920 AND `id`=0) OR (`questId`=25920 AND `id`=1) OR (`questId`=25920 AND `id`=1) OR (`questId`=25920 AND `id`=1) OR (`questId`=25920 AND `id`=1) OR (`questId`=25920 AND `id`=1) OR (`questId`=25920 AND `id`=1) OR (`questId`=25920 AND `id`=1) OR (`questId`=25920 AND `id`=1) OR (`questId`=25920 AND `id`=1) OR (`questId`=25921 AND `id`=1) OR (`questId`=25921 AND `id`=2) OR (`questId`=25922 AND `id`=0) OR (`questId`=25922 AND `id`=1) OR (`questId`=25922 AND `id`=2) OR (`questId`=25922 AND `id`=3) OR (`questId`=25922 AND `id`=4) OR (`questId`=25536 AND `id`=0) OR (`questId`=25536 AND `id`=0) OR (`questId`=25536 AND `id`=0) OR (`questId`=25536 AND `id`=0) OR (`questId`=25536 AND `id`=0) OR (`questId`=25536 AND `id`=0) OR (`questId`=25536 AND `id`=1) OR (`questId`=25535 AND `id`=0);
INSERT INTO `quest_poi_points` (`questId`, `id`, `idx`, `x`, `y`) VALUES
(25900, 0, 0, -6445, 4178), -- Making Contact
(25900, 1, 0, -6445, 4178), -- Making Contact
(25908, 5, 0, -6366, 3727), -- Stick it to Them
(25908, 5, 1, -6343, 3769), -- Stick it to Them
(25908, 5, 2, -6332, 3824), -- Stick it to Them
(25908, 5, 3, -6334, 3897), -- Stick it to Them
(25908, 5, 4, -6352, 3942), -- Stick it to Them
(25908, 5, 5, -6382, 3991), -- Stick it to Them
(25908, 5, 6, -6444, 4026), -- Stick it to Them
(25908, 5, 7, -6534, 4050), -- Stick it to Them
(25908, 5, 8, -6602, 4053), -- Stick it to Them
(25908, 5, 9, -6694, 4010), -- Stick it to Them
(25908, 5, 10, -6761, 3911), -- Stick it to Them
(25908, 5, 11, -6769, 3857), -- Stick it to Them
(25908, 6, 0, -6445, 4178), -- Stick it to Them
(25908, 7, 0, -6539, 3748), -- Stick it to Them
(25908, 7, 1, -6449, 3771), -- Stick it to Them
(25908, 7, 2, -6432, 3834), -- Stick it to Them
(25908, 7, 3, -6435, 3873), -- Stick it to Them
(25908, 7, 4, -6460, 3924), -- Stick it to Them
(25908, 7, 5, -6539, 3958), -- Stick it to Them
(25908, 7, 6, -6578, 3948), -- Stick it to Them
(25908, 7, 7, -6629, 3930), -- Stick it to Them
(25908, 7, 8, -6652, 3899), -- Stick it to Them
(25908, 7, 9, -6666, 3840), -- Stick it to Them
(25908, 7, 10, -6622, 3780), -- Stick it to Them
(25908, 7, 11, -6585, 3752), -- Stick it to Them
(25907, 0, 0, -6445, 4178), -- Slave Labor
(25907, 1, 0, -6616, 3950), -- Slave Labor
(25907, 1, 1, -6601, 3958), -- Slave Labor
(25907, 1, 2, -6602, 3970), -- Slave Labor
(25907, 1, 3, -6649, 4009), -- Slave Labor
(25907, 1, 4, -6650, 3995), -- Slave Labor
(25907, 2, 0, -6382, 3766), -- Slave Labor
(25907, 2, 1, -6374, 3767), -- Slave Labor
(25907, 2, 2, -6401, 3810), -- Slave Labor
(25907, 2, 3, -6410, 3809), -- Slave Labor
(25907, 2, 4, -6426, 3807), -- Slave Labor
(25907, 2, 5, -6437, 3800), -- Slave Labor
(25907, 2, 6, -6431, 3791), -- Slave Labor
(25907, 2, 7, -6422, 3781), -- Slave Labor
(25907, 3, 0, -6519, 3967), -- Slave Labor
(25907, 3, 1, -6504, 3970), -- Slave Labor
(25907, 3, 2, -6498, 3972), -- Slave Labor
(25907, 3, 3, -6491, 3979), -- Slave Labor
(25907, 3, 4, -6482, 4005), -- Slave Labor
(25907, 3, 5, -6519, 3994), -- Slave Labor
(25907, 3, 6, -6519, 3984), -- Slave Labor
(25907, 4, 0, -6434, 3894), -- Slave Labor
(25907, 4, 1, -6422, 3895), -- Slave Labor
(25907, 4, 2, -6383, 3910), -- Slave Labor
(25907, 4, 3, -6378, 3918), -- Slave Labor
(25907, 4, 4, -6381, 3938), -- Slave Labor
(25907, 4, 5, -6406, 3939), -- Slave Labor
(25907, 4, 6, -6431, 3923), -- Slave Labor
(25907, 4, 7, -6441, 3906), -- Slave Labor
(25907, 5, 0, -6692, 3864), -- Slave Labor
(25907, 5, 1, -6674, 3866), -- Slave Labor
(25907, 5, 2, -6677, 3886), -- Slave Labor
(25907, 5, 3, -6687, 3895), -- Slave Labor
(25907, 5, 4, -6695, 3901), -- Slave Labor
(25907, 5, 5, -6726, 3908), -- Slave Labor
(25907, 5, 6, -6737, 3901), -- Slave Labor
(25907, 5, 7, -6699, 3867), -- Slave Labor
(25909, 0, 0, -6445, 4178), -- Capture the Crab
(25909, 1, 0, -6291, 3743), -- Capture the Crab
(25909, 1, 1, -6273, 3836), -- Capture the Crab
(25909, 1, 2, -6288, 3933), -- Capture the Crab
(25909, 1, 3, -6320, 4003), -- Capture the Crab
(25909, 2, 0, -6827, 3824), -- Capture the Crab
(25909, 2, 1, -6693, 4081), -- Capture the Crab
(25909, 2, 2, -6766, 4024), -- Capture the Crab
(25909, 2, 3, -6807, 3940), -- Capture the Crab
(25916, 0, 0, -6445, 4178), -- Breaking Through
(25916, 1, 0, -6445, 4178), -- Breaking Through
(25917, 0, 0, -6369, 3641), -- We Are Not Alone
(25919, 0, 0, -6522, 3538), -- Body Blows
(25919, 0, 1, -6400, 3590), -- Body Blows
(25919, 0, 2, -6295, 3693), -- Body Blows
(25919, 0, 3, -6254, 3810), -- Body Blows
(25919, 0, 4, -6256, 3919), -- Body Blows
(25919, 0, 5, -6798, 3928), -- Body Blows
(25919, 0, 6, -6814, 3901), -- Body Blows
(25919, 0, 7, -6837, 3792), -- Body Blows
(25919, 0, 8, -6809, 3700), -- Body Blows
(25919, 0, 9, -6765, 3626), -- Body Blows
(25919, 0, 10, -6686, 3564), -- Body Blows
(25919, 1, 0, -6369, 3641), -- Body Blows
(25918, 0, 0, -6502, 3559), -- Hopelessly Gearless
(25918, 0, 1, -6482, 3563), -- Hopelessly Gearless
(25918, 0, 2, -6396, 3683), -- Hopelessly Gearless
(25918, 0, 3, -6410, 3702), -- Hopelessly Gearless
(25918, 0, 4, -6429, 3720), -- Hopelessly Gearless
(25918, 0, 5, -6444, 3732), -- Hopelessly Gearless
(25918, 0, 6, -6667, 3813), -- Hopelessly Gearless
(25918, 0, 7, -6764, 3803), -- Hopelessly Gearless
(25918, 0, 8, -6819, 3743), -- Hopelessly Gearless
(25918, 0, 9, -6752, 3630), -- Hopelessly Gearless
(25918, 0, 10, -6728, 3608), -- Hopelessly Gearless
(25918, 1, 0, -6371, 3640), -- Hopelessly Gearless
(25920, 0, 0, -6358, 3644), -- Still Valuable
(25920, 1, 0, -6497, 3563), -- Still Valuable
(25920, 1, 1, -6454, 3601), -- Still Valuable
(25920, 1, 2, -6420, 3654), -- Still Valuable
(25920, 1, 3, -6421, 3701), -- Still Valuable
(25920, 1, 4, -6675, 3811), -- Still Valuable
(25920, 1, 5, -6771, 3794), -- Still Valuable
(25920, 1, 6, -6765, 3675), -- Still Valuable
(25920, 1, 7, -6654, 3595), -- Still Valuable
(25920, 1, 8, -6504, 3564), -- Still Valuable
(25921, 1, 0, -6445, 4178), -- Overseer Idra'kess
(25921, 2, 0, -6586, 3905), -- Overseer Idra'kess
(25922, 0, 0, -6445, 4178), -- Waking the Beast
(25922, 1, 0, -6549, 4242), -- Waking the Beast
(25922, 2, 0, -6445, 4178), -- Waking the Beast
(25922, 3, 0, -6549, 4242), -- Waking the Beast
(25922, 4, 0, -6560, 4323), -- Waking the Beast
(25536, 0, 0, -6430, 4442), -- Cold Welcome
(25536, 0, 1, -6279, 4476), -- Cold Welcome
(25536, 0, 2, -6243, 4516), -- Cold Welcome
(25536, 0, 3, -6176, 4601), -- Cold Welcome
(25536, 0, 4, -6193, 4697), -- Cold Welcome
(25536, 0, 5, -6309, 4737), -- Cold Welcome
(25536, 1, 0, -6650, 4382), -- Cold Welcome
(25535, 0, 0, -6344, 4305); -- A Powerful Need To Eat
