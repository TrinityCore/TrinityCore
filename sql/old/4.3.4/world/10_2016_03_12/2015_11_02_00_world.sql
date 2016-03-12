-- Twilight Highlands Area: 5140 Highbank Phase 169
SET @CGUID := 250151;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+247;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 45167, 0, 1, 169, 0, -4907.8, -6605.99, 20.28953, 5.445427, 120, 0, 0), -- Kurdran Wildhammer
(@CGUID+1, 45170, 0, 1, 169, 0, -4916.22, -6616.91, 19.04593, 0.01745329, 120, 0, 0), -- Simon Chandler
(@CGUID+2, 45173, 0, 1, 169, 0, -4885.1, -6623.98, 9.904303, 4.869469, 120, 0, 0), -- Talaa
(@CGUID+3, 50381, 0, 1, 169, 0, -4838.097, -6589.958, 9.648396, 0.122173, 120, 0, 0), -- Misty Merriweather <Hide & Leather Trader>
(@CGUID+4, 50382, 0, 1, 169, 0, -4847.408, -6610.934, 9.500094, 0.8377581, 120, 0, 0), -- Brundall Chiselgut <Metal Trader>
(@CGUID+5, 50386, 0, 1, 169, 0, -4860.052, -6576.734, 9.500094, 5.427974, 120, 0, 0), -- Sal Ferraga <Cloth Trader>
(@CGUID+6, 50458, 0, 1, 169, 0, -4864.509, -6586.958, 9.500094, 0, 120, 0, 0), -- Deorim <Enchanting Supplies>
(@CGUID+7, 45256, 0, 1, 169, 0, -4968.62, -6452, 5.86154, 0.7679449, 120, 0, 0), -- Dave's Camera Bunny
(@CGUID+8, 45869, 0, 1, 169, 0, -4899.32, -6645.05, 33.39563, 1.169371, 120, 0, 0), -- Highbank Shaman
(@CGUID+9, 45869, 0, 1, 169, 0, -4880.32, -6646.61, 33.39573, 2.024582, 120, 0, 0), -- Highbank Shaman
(@CGUID+10, 45869, 0, 1, 169, 0, -4872.19, -6639.9, 33.39553, 2.478368, 120, 0, 0), -- Highbank Shaman
(@CGUID+11, 45869, 0, 1, 169, 0, -4867.2, -6624.95, 33.39553, 3.141593, 120, 0, 0), -- Highbank Shaman
(@CGUID+12, 45869, 0, 1, 169, 0, -4901.56, -6637.1, 10.92023, 0.8377581, 120, 0, 0), -- Highbank Shaman
(@CGUID+13, 45869, 0, 1, 169, 0, -4877.61, -6615.96, 10.92323, 3.612832, 120, 0, 0), -- Highbank Shaman
(@CGUID+14, 47119, 0, 1, 169, 0, -4866.6, -6741.57, 9.500103, 0, 120, 0, 0), -- Glenn Arbuckle <Gryphon Master>
(@CGUID+15, 49008, 0, 1, 169, 0, -4861.115, -6678.806, 8.240196, 1.553343, 120, 0, 0), -- Axebite Infantry
(@CGUID+16, 49008, 0, 1, 169, 0, -4847.016, -6674.309, 6.887068, 2.408554, 120, 0, 0), -- Axebite Infantry
(@CGUID+17, 49008, 0, 1, 169, 0, -4903.969, -6730.637, 0.7164544, 0.8377581, 120, 0, 0), -- Axebite Infantry
(@CGUID+18, 49008, 0, 1, 169, 0, -4860.255, -6671.849, 8.488512, 1.745329, 120, 0, 0), -- Axebite Infantry
(@CGUID+19, 49008, 0, 1, 169, 0, -4855.073, -6673.564, 7.895617, 1.867502, 120, 0, 0), -- Axebite Infantry
(@CGUID+20, 49008, 0, 1, 169, 0, -4925.936, -6743.022, 5.578823, 0.8203048, 120, 0, 0), -- Axebite Infantry
(@CGUID+21, 49008, 0, 1, 169, 0, -4869.255, -6716.262, 5.013374, 1.012291, 120, 0, 0), -- Axebite Infantry
(@CGUID+22, 49008, 0, 1, 169, 0, -4825.771, -6690.893, 4.413385, 5.951573, 120, 0, 0), -- Axebite Infantry
(@CGUID+23, 49008, 0, 1, 169, 0, -4858.743, -6669.259, 8.462119, 1.745329, 120, 0, 0), -- Axebite Infantry
(@CGUID+24, 49008, 0, 1, 169, 0, -4890.707, -6716.463, 4.898449, 0.4886922, 120, 0, 0), -- Axebite Infantry
(@CGUID+25, 49008, 0, 1, 169, 0, -4908.384, -6728.556, 0.7164544, 0.4014257, 120, 0, 0), -- Axebite Infantry
(@CGUID+26, 49008, 0, 1, 169, 0, -4927.963, -6740.297, 5.508946, 0.2443461, 120, 0, 0), -- Axebite Infantry
(@CGUID+27, 49008, 0, 1, 169, 0, -4882.052, -6720.606, 4.56483, 1.012291, 120, 0, 0), -- Axebite Infantry
(@CGUID+28, 49008, 0, 1, 169, 0, -4819.941, -6686.005, 4.512493, 0.3316126, 120, 0, 0), -- Axebite Infantry
(@CGUID+29, 49008, 0, 1, 169, 0, -4851.174, -6668.561, 7.951297, 1.954769, 120, 0, 0), -- Axebite Infantry
(@CGUID+30, 49008, 0, 1, 169, 0, -4810.144, -6692.25, 4.433012, 6.213372, 120, 0, 0), -- Axebite Infantry
(@CGUID+31, 49008, 0, 1, 169, 0, -4939.653, -6727.825, 5.702463, 6.248279, 120, 0, 0), -- Axebite Infantry
(@CGUID+32, 49008, 0, 1, 169, 0, -4770.608, -6711.078, 4.45895, 5.5676, 120, 0, 0), -- Axebite Infantry
(@CGUID+33, 49008, 0, 1, 169, 0, -4771.059, -6704.443, 4.412205, 5.899213, 120, 0, 0), -- Axebite Infantry
(@CGUID+34, 49008, 0, 1, 169, 0, -4810.844, -6646.46, 4.543884, 1.797689, 120, 0, 0), -- Axebite Infantry
(@CGUID+35, 49008, 0, 1, 169, 0, -4745.971, -6667.441, 4.617817, 5.986479, 120, 0, 0), -- Axebite Infantry
(@CGUID+36, 49008, 0, 1, 169, 0, -4736.069, -6665.521, 5.166455, 6.230825, 120, 0, 0), -- Axebite Infantry
(@CGUID+37, 49008, 0, 1, 169, 0, -4736.694, -6663.424, 5.110536, 0.2094395, 120, 0, 0), -- Axebite Infantry
(@CGUID+38, 49008, 0, 1, 169, 0, -4776.533, -6632.569, 4.418663, 0.5759587, 120, 0, 0), -- Axebite Infantry
(@CGUID+39, 49008, 0, 1, 169, 0, -4840.448, -6601.53, 9.500094, 2.600541, 120, 0, 0), -- Axebite Infantry
(@CGUID+40, 49008, 0, 1, 169, 0, -4847.731, -6597.38, 9.500094, 2.583087, 120, 0, 0), -- Axebite Infantry
(@CGUID+41, 49008, 0, 1, 169, 0, -4848.913, -6599.894, 9.500094, 2.076942, 120, 0, 0), -- Axebite Infantry
(@CGUID+42, 49008, 0, 1, 169, 0, -5008.031, -6812.045, -1.728834, 5.602507, 120, 0, 0), -- Axebite Infantry
(@CGUID+43, 49008, 0, 1, 169, 0, -4981.144, -6823.128, -1.560934, 5.72468, 120, 0, 0), -- Axebite Infantry
(@CGUID+44, 49008, 0, 1, 169, 0, -4922.627, -6842.366, -1.685967, 3.316126, 120, 0, 0), -- Axebite Infantry
(@CGUID+45, 49008, 0, 1, 169, 0, -4961.75, -6837.153, -1.531922, 6.213372, 120, 0, 0), -- Axebite Infantry
(@CGUID+46, 49008, 0, 1, 169, 0, -5000.25, -6832.514, -1.540749, 1.989675, 120, 0, 0), -- Axebite Infantry
(@CGUID+47, 49008, 0, 1, 169, 0, -5047.971, -6742.172, -1.612649, 5.131268, 120, 0, 0), -- Axebite Infantry
(@CGUID+48, 49008, 0, 1, 169, 0, -5044.627, -6758.557, -1.773251, 0.8552113, 120, 0, 0), -- Axebite Infantry
(@CGUID+49, 49008, 0, 1, 169, 0, -5035.184, -6775.264, -1.618659, 5.67232, 120, 0, 0), -- Axebite Infantry
(@CGUID+50, 49008, 0, 1, 169, 0, -5050.337, -6706.738, -1.727231, 1.064651, 120, 0, 0), -- Axebite Infantry
(@CGUID+51, 49008, 0, 1, 169, 0, -5054.03, -6722.918, -1.785994, 1.308997, 120, 0, 0), -- Axebite Infantry
(@CGUID+52, 49009, 0, 1, 169, 0, -4907.776, -6731.543, 0.7164544, 0.8377581, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+53, 49009, 0, 1, 169, 0, -4854.491, -6686.615, 5.995787, 1.675516, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+54, 49009, 0, 1, 169, 0, -4818.045, -6737.342, 9.500101, 5.689773, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+55, 49009, 0, 1, 169, 0, -4961.53, -6757.149, 4.700684, 3.089233, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+56, 49009, 0, 1, 169, 0, -4959.76, -6754.802, 4.666667, 3.246312, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+57, 49009, 0, 1, 169, 0, -4955.168, -6769.96, 5.421104, 1.291544, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+58, 49009, 0, 1, 169, 0, -4804.037, -6650.535, 4.448647, 2.024582, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+59, 49009, 0, 1, 169, 0, -4817.3, -6619.95, 7.013344, 2.495821, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+60, 49009, 0, 1, 169, 0, -4962.615, -6767.698, 6.316628, 0.7330383, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+61, 49009, 0, 1, 169, 0, -4974.163, -6756.333, 5.416175, 3.124139, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+62, 49009, 0, 1, 169, 0, -4979.939, -6753.259, 5.281884, 3.804818, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+63, 49009, 0, 1, 169, 0, -4974.186, -6752.128, 5.117718, 3.612832, 120, 0, 0), -- Bilgewater Gunman
(@CGUID+64, 49020, 0, 1, 169, 0, -4850.439, -6596.811, 9.500094, 5.51524, 120, 0, 0), -- Fargo Flintlocke
(@CGUID+65, 49022, 0, 1, 169, 0, -4762.639, -6672.523, 4.454048, 2.495821, 120, 0, 0), -- Lieutenant Fawkes
(@CGUID+66, 49025, 0, 1, 169, 0, -4733.851, -6764.844, 44.57782, 2.478368, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+67, 49025, 0, 1, 169, 0, -5006.554, -6774.135, 44.4698, 1.64061, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+68, 49025, 0, 1, 169, 0, -4720.302, -6770.793, 44.81567, 5.72468, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+69, 49025, 0, 1, 169, 0, -5001.481, -6758.92, 44.4698, 4.939282, 120, 0, 0), -- Highbank Cannoneer
(@CGUID+70, 49341, 0, 1, 169, 0, -4904.705, -6656.596, 31.99786, 3.979351, 120, 0, 0), -- Highbank Marksman
(@CGUID+71, 49341, 0, 1, 169, 0, -4800.037, -6773.465, 17.75586, 4.834562, 120, 0, 0), -- Highbank Marksman
(@CGUID+72, 49341, 0, 1, 169, 0, -4765.715, -6771.353, 17.75253, 4.991642, 120, 0, 0), -- Highbank Marksman
(@CGUID+73, 49341, 0, 1, 169, 0, -4786.927, -6770.964, 17.66897, 3.199598, 120, 0, 0), -- Highbank Marksman
(@CGUID+74, 49341, 0, 1, 169, 0, -4868.337, -6607.35, 31.9134, 2.304971, 120, 0, 0), -- Highbank Marksman
(@CGUID+75, 49341, 0, 1, 169, 0, -4906.21, -6641.944, 31.91726, 5.412406, 120, 0, 0), -- Highbank Marksman
(@CGUID+76, 49341, 0, 1, 169, 0, -4881.326, -6596.688, 31.91219, 2.264606, 120, 0, 0), -- Highbank Marksman
(@CGUID+77, 49341, 0, 1, 169, 0, -4809.083, -6576.217, 17.34796, 5.952751, 120, 0, 0), -- Highbank Marksman
(@CGUID+78, 49341, 0, 1, 169, 0, -4910.056, -6595.374, 31.99206, 2.373648, 120, 0, 0), -- Highbank Marksman
(@CGUID+79, 49341, 0, 1, 169, 0, -4849.226, -6563.472, 17.39647, 4.660029, 120, 0, 0), -- Highbank Marksman
(@CGUID+80, 49341, 0, 1, 169, 0, -4821.847, -6570.323, 17.40815, 1.047198, 120, 0, 0), -- Highbank Marksman
(@CGUID+81, 49341, 0, 1, 169, 0, -4921.393, -6629.287, 31.91347, 4.528966, 120, 0, 0), -- Highbank Marksman
(@CGUID+82, 49341, 0, 1, 169, 0, -4800.696, -6577.948, 17.43129, 1.239184, 120, 0, 0), -- Highbank Marksman
(@CGUID+83, 49341, 0, 1, 169, 0, -4713.76, -6641.471, 17.75548, 0.6981317, 120, 0, 0), -- Highbank Marksman
(@CGUID+84, 49341, 0, 1, 169, 0, -4698.115, -6707.241, 17.80357, 6.108652, 120, 0, 0), -- Highbank Marksman
(@CGUID+85, 49341, 0, 1, 169, 0, -4693.582, -6673.078, 17.79169, 0.5061455, 120, 0, 0), -- Highbank Marksman
(@CGUID+86, 49341, 0, 1, 169, 0, -4703.444, -6740.853, 17.324, 5.67232, 120, 0, 0), -- Highbank Marksman
(@CGUID+87, 49341, 0, 1, 169, 0, -4986.333, -6761.665, 44.7027, 0.296706, 120, 0, 0), -- Highbank Marksman
(@CGUID+88, 49342, 0, 1, 169, 0, -4886.281, -6707.604, 5.243135, 4.764749, 120, 0, 0), -- Highbank Guardsman
(@CGUID+89, 49342, 0, 1, 169, 0, -4876.569, -6706.232, 4.979062, 3.882104, 120, 0, 0), -- Highbank Guardsman
(@CGUID+90, 49342, 0, 1, 169, 0, -4875.525, -6715.788, 4.662216, 0.7220657, 120, 0, 0), -- Highbank Guardsman
(@CGUID+91, 49342, 0, 1, 169, 0, -4877.607, -6714.956, 4.532949, 0.7220852, 120, 0, 0), -- Highbank Guardsman
(@CGUID+92, 49342, 0, 1, 169, 0, -4875.236, -6707.721, 4.804262, 3.882395, 120, 0, 0), -- Highbank Guardsman
(@CGUID+93, 49342, 0, 1, 169, 0, -4840.88, -6702.156, 4.854588, 6.038839, 120, 0, 0), -- Highbank Guardsman
(@CGUID+94, 49342, 0, 1, 169, 0, -4811.366, -6726.056, 7.455061, 2.373648, 120, 0, 0), -- Highbank Guardsman
(@CGUID+95, 49342, 0, 1, 169, 0, -4900.699, -6701.292, 5.093423, 5.48628, 120, 0, 0), -- Highbank Guardsman
(@CGUID+96, 49342, 0, 1, 169, 0, -4904.781, -6700.305, 4.821856, 5.549376, 120, 0, 0), -- Highbank Guardsman
(@CGUID+97, 49342, 0, 1, 169, 0, -4865.755, -6688.656, 6.968502, 5.480334, 120, 0, 0), -- Highbank Guardsman
(@CGUID+98, 49342, 0, 1, 169, 0, -4821.374, -6733.881, 9.477418, 0.06756632, 120, 0, 0), -- Highbank Guardsman
(@CGUID+99, 49342, 0, 1, 169, 0, -4817.192, -6735.533, 9.477418, 0.08493628, 120, 0, 0), -- Highbank Guardsman
(@CGUID+100, 49342, 0, 1, 169, 0, -4823.991, -6724.335, 7.478768, 0.7330383, 120, 0, 0), -- Highbank Guardsman
(@CGUID+101, 49342, 0, 1, 169, 0, -4839.175, -6702.557, 4.947917, 2.9147, 120, 0, 0), -- Highbank Guardsman
(@CGUID+102, 49342, 0, 1, 169, 0, -4868.38, -6659.069, 10.93896, 5.462881, 120, 0, 0), -- Highbank Guardsman
(@CGUID+103, 49342, 0, 1, 169, 0, -4791.365, -6706.787, 5.240479, 1.710423, 120, 0, 0), -- Highbank Guardsman
(@CGUID+104, 49342, 0, 1, 169, 0, -4828.152, -6643.914, 9.286678, 3.923418, 120, 0, 0), -- Highbank Guardsman
(@CGUID+105, 49342, 0, 1, 169, 0, -4862.175, -6653.472, 10.9392, 5.340707, 120, 0, 0), -- Highbank Guardsman
(@CGUID+106, 49342, 0, 1, 169, 0, -4882.684, -6644.769, 10.93652, 2.181662, 120, 0, 0), -- Highbank Guardsman
(@CGUID+107, 49342, 0, 1, 169, 0, -4875.171, -6644.341, 10.85477, 2.259258, 120, 0, 0), -- Highbank Guardsman
(@CGUID+108, 49342, 0, 1, 169, 0, -4884.031, -6656.323, 10.93815, 1.518436, 120, 0, 0), -- Highbank Guardsman
(@CGUID+109, 49342, 0, 1, 169, 0, -4876.697, -6645.636, 10.85494, 2.259501, 120, 0, 0), -- Highbank Guardsman
(@CGUID+110, 49342, 0, 1, 169, 0, -4883.901, -6654.582, 10.93833, 4.642576, 120, 0, 0), -- Highbank Guardsman
(@CGUID+111, 49342, 0, 1, 169, 0, -4873.755, -6637.144, 10.93653, 2.478368, 120, 0, 0), -- Highbank Guardsman
(@CGUID+112, 49342, 0, 1, 169, 0, -4814.971, -6642.113, 5.723929, 0.1047198, 120, 0, 0), -- Highbank Guardsman
(@CGUID+113, 49342, 0, 1, 169, 0, -4756.418, -6714.05, 7.768574, 2.321288, 120, 0, 0), -- Highbank Guardsman
(@CGUID+114, 49342, 0, 1, 169, 0, -4755.519, -6696.524, 7.453988, 3.961897, 120, 0, 0), -- Highbank Guardsman
(@CGUID+115, 49342, 0, 1, 169, 0, -4800.522, -6623.179, 5.225997, 4.747295, 120, 0, 0), -- Highbank Guardsman
(@CGUID+116, 49342, 0, 1, 169, 0, -4742.016, -6655.908, 5.462309, 3.961897, 120, 0, 0), -- Highbank Guardsman
(@CGUID+117, 49342, 0, 1, 169, 0, -4826.598, -6617.851, 8.566182, 5.441192, 120, 0, 0), -- Highbank Guardsman
(@CGUID+118, 49342, 0, 1, 169, 0, -4825.168, -6616.511, 8.154016, 5.477563, 120, 0, 0), -- Highbank Guardsman
(@CGUID+119, 49342, 0, 1, 169, 0, -4738.507, -6673.887, 5.853456, 2.478368, 120, 0, 0), -- Highbank Guardsman
(@CGUID+120, 49342, 0, 1, 169, 0, -4743.481, -6744.045, 5.240479, 2.356194, 120, 0, 0), -- Highbank Guardsman
(@CGUID+121, 49342, 0, 1, 169, 0, -4820.243, -6612.654, 7.379973, 2.346351, 120, 0, 0), -- Highbank Guardsman
(@CGUID+122, 49342, 0, 1, 169, 0, -4821.639, -6614.076, 7.709207, 2.356194, 120, 0, 0), -- Highbank Guardsman
(@CGUID+123, 49342, 0, 1, 169, 0, -4723.26, -6660.8, 5.258198, 3.543018, 120, 0, 0), -- Highbank Guardsman
(@CGUID+124, 49342, 0, 1, 169, 0, -4704.378, -6644.24, 7.952923, 4.607669, 120, 0, 0), -- Highbank Guardsman
(@CGUID+125, 49342, 0, 1, 169, 0, -4722.024, -6756.346, 8.167795, 3.473205, 120, 0, 0), -- Highbank Guardsman
(@CGUID+126, 49342, 0, 1, 169, 0, -4983.077, -6731.653, 5.221353, 2.327248, 120, 0, 0), -- Highbank Guardsman
(@CGUID+127, 49342, 0, 1, 169, 0, -4982.356, -6752.124, 5.525763, 0.541052, 120, 0, 0), -- Highbank Guardsman
(@CGUID+128, 49342, 0, 1, 169, 0, -4983.703, -6725.988, 5.219322, 5.742133, 120, 0, 0), -- Highbank Guardsman
(@CGUID+129, 49342, 0, 1, 169, 0, -4979.617, -6732.406, 5.357412, 2.270613, 120, 0, 0), -- Highbank Guardsman
(@CGUID+130, 49343, 0, 1, 169, 0, -4886.837, -6608.656, 1.691776, 3.071779, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+131, 49343, 0, 1, 169, 0, -4899.962, -6628.552, 11.00575, 3.822271, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+132, 49343, 0, 1, 169, 0, -4888.41, -6608.632, 1.692902, 0.01745329, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+133, 49343, 0, 1, 169, 0, -4884.689, -6615.5, 1.690678, 5.375614, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+134, 49343, 0, 1, 169, 0, -4904.833, -6632.549, 10.95766, 0.6457718, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+135, 49344, 0, 1, 169, 0, -4735.056, -6763.731, 44.57782, 5.51524, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+136, 49344, 0, 1, 169, 0, -5006.55, -6772.502, 44.4698, 4.677482, 120, 0, 0), -- Highbank Prison Guard
(@CGUID+137, 49350, 0, 1, 169, 0, -4912.082, -6755.543, 15.34799, 4.066617, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+138, 49350, 0, 1, 169, 0, -4912.915, -6757.125, 15.34803, 0.9948376, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+139, 49350, 0, 1, 169, 0, -4923.884, -6726.795, 5.407431, 1.871382, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+140, 49350, 0, 1, 169, 0, -4940.458, -6729.863, 5.63989, 1.727876, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+141, 49350, 0, 1, 169, 0, -4932.899, -6741.071, 5.454586, 5.305801, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+142, 49350, 0, 1, 169, 0, -4924.174, -6731.894, 5.466965, 3.455752, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+143, 49350, 0, 1, 169, 0, -4925.74, -6732.766, 5.476225, 0.3839724, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+144, 49350, 0, 1, 169, 0, -4940.899, -6706.333, 14.19617, 5.550147, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+145, 49350, 0, 1, 169, 0, -4940.958, -6728.156, 5.704298, 4.799655, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+146, 49350, 0, 1, 169, 0, -4939.448, -6707.368, 13.90087, 2.338741, 120, 0, 0), -- Tidebreaker Sailor
(@CGUID+147, 49354, 0, 1, 169, 0, -4851.757, -6760.769, 12.39042, 5.183628, 120, 0, 0), -- Highbank Woodworker
(@CGUID+148, 49354, 0, 1, 169, 0, -4834.913, -6749.266, 11.62409, 4.642576, 120, 0, 0), -- Highbank Woodworker
(@CGUID+149, 49354, 0, 1, 169, 0, -4842.981, -6753.441, 11.64238, 1.850049, 120, 0, 0), -- Highbank Woodworker
(@CGUID+150, 49354, 0, 1, 169, 0, -4831.024, -6759.908, 11.64906, 5.637414, 120, 0, 0), -- Highbank Woodworker
(@CGUID+151, 49354, 0, 1, 169, 0, -4806.628, -6750.016, 12.7037, 3.700098, 120, 0, 0), -- Highbank Woodworker
(@CGUID+152, 49354, 0, 1, 169, 0, -4814.665, -6758.474, 9.500101, 4.921828, 120, 0, 0), -- Highbank Woodworker
(@CGUID+153, 49354, 0, 1, 169, 0, -4783.037, -6749.033, 11.83597, 0.4886922, 120, 0, 0), -- Highbank Woodworker
(@CGUID+154, 49354, 0, 1, 169, 0, -4793.875, -6753.448, 11.86547, 6.143559, 120, 0, 0), -- Highbank Woodworker
(@CGUID+155, 49354, 0, 1, 169, 0, -4735.556, -6702.156, 12.87715, 4.380776, 120, 0, 0), -- Highbank Woodworker
(@CGUID+156, 49354, 0, 1, 169, 0, -4729.318, -6695.554, 12.88499, 1.727876, 120, 0, 0), -- Highbank Woodworker
(@CGUID+157, 49354, 0, 1, 169, 0, -4725.353, -6719.813, 13.02115, 5.67232, 120, 0, 0), -- Highbank Woodworker
(@CGUID+158, 49354, 0, 1, 169, 0, -4717.278, -6691.403, 9.500094, 3.420845, 120, 0, 0), -- Highbank Woodworker
(@CGUID+159, 49354, 0, 1, 169, 0, -4722.999, -6706.184, 12.89981, 6.021386, 120, 0, 0), -- Highbank Woodworker
(@CGUID+160, 49366, 0, 1, 169, 0, -4769.646, -6669.738, 4.470486, 0.03490658, 120, 0, 0), -- Highbank Marksman
(@CGUID+161, 49366, 0, 1, 169, 0, -4768.675, -6666.328, 4.470482, 0.03490658, 120, 0, 0), -- Highbank Marksman
(@CGUID+162, 49366, 0, 1, 169, 0, -4769.774, -6667.554, 4.453924, 0.03490658, 120, 0, 0), -- Highbank Marksman
(@CGUID+163, 49366, 0, 1, 169, 0, -4768.62, -6668.627, 4.453924, 0.03490658, 120, 0, 0), -- Highbank Marksman
(@CGUID+164, 49366, 0, 1, 169, 0, -4769.752, -6665.057, 4.45496, 0.03490658, 120, 0, 0), -- Highbank Marksman
(@CGUID+165, 49686, 0, 1, 169, 0, -4891.307, -6599.856, 10.91657, 0.6108652, 120, 0, 0), -- Innkeeper Teresa <Innkeeper>
(@CGUID+166, 49688, 0, 1, 169, 0, -4916.222, -6621.262, 10.91657, 3.874631, 120, 0, 0), -- Innkeeper Francis <Innkeeper>
(@CGUID+167, 49689, 0, 1, 169, 0, -4878.781, -6686.499, 9.501736, 6.265732, 120, 0, 0), -- Bonnie Hennigan <Stable Master>
(@CGUID+168, 49695, 0, 1, 169, 0, -4852.063, -6610.596, 9.500094, 0.4363323, 120, 0, 0), -- Dorgan Slagfist <Blacksmith>
(@CGUID+169, 49702, 0, 1, 169, 0, -4822.54, -6580.802, 9.500094, 4.677482, 120, 0, 0), -- Frank Natale <Engineering & Mining Supplies>
(@CGUID+170, 49703, 0, 1, 169, 0, -4833.13, -6577.019, 9.500094, 3.961897, 120, 0, 0), -- Casandra Downs <Alchemy & Inscription Supplies>
(@CGUID+171, 49704, 0, 1, 169, 0, -4849.863, -6572.797, 9.500094, 2.96706, 120, 0, 0), -- Evan Silvia <Cook>
(@CGUID+172, 49705, 0, 1, 169, 0, -4860.858, -6578.276, 9.500094, 5.742133, 120, 0, 0), -- Leah Drewry <Tailoring Supplies>
(@CGUID+173, 49707, 0, 1, 169, 0, -4858.299, -6575.705, 9.500094, 5.148721, 120, 0, 0), -- Oslow Pliny <Jewelcrafting Supplies>
(@CGUID+174, 49714, 0, 1, 169, 0, -4836.952, -6593.335, 9.500094, 0.7330383, 120, 0, 0), -- Alexandra Merriweather <Leatherworking Supplies>
(@CGUID+175, 49721, 0, 1, 169, 0, -4858.271, -6601.838, 9.500094, 3.316126, 120, 0, 0), -- Frederick Zyda <Furnace Master>
(@CGUID+176, 49723, 0, 1, 169, 0, -4841.019, -6616.229, 9.500092, 0.3665192, 120, 0, 0), -- Philip O'Tool <Weapons Vendor>
(@CGUID+177, 49726, 0, 1, 169, 0, -4856.569, -6606.094, 9.500094, 3.857178, 120, 0, 0), -- Richard Maschner <Blacksmithing Supplies>
(@CGUID+178, 49729, 0, 1, 169, 0, -4798.946, -6596.738, 9.500094, 3.543018, 120, 0, 0), -- Lynn Baxter <Morale Officer>
(@CGUID+179, 49733, 0, 1, 169, 0, -4836.772, -6575.698, 9.5, 4.607669, 120, 0, 0), -- Ashley Downs <Reagents>
(@CGUID+180, 50134, 0, 1, 169, 0, -4864.368, -6584.908, 9.500094, 6.195919, 120, 0, 0), --  Senthii <Shard Trader>
(@CGUID+181, 45179, 0, 1, 169, 0, -5001.335, -6547.382, -57.77094, 2.329497, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+182, 45179, 0, 1, 169, 0, -4921.912, -6513.803, -54.41761, 1.001083, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+183, 45179, 0, 1, 169, 0, -4988.98, -6495.237, -58.33754, 2.931485, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+184, 45179, 0, 1, 169, 0, -5016.293, -6583.675, -17.31591, 3.255974, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+185, 45179, 0, 1, 169, 0, -5039.099, -6453.793, -27.30685, 4.039469, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+186, 45179, 0, 1, 169, 0, -5033.896, -6477.784, -29.34386, 1.072913, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+187, 45179, 0, 1, 169, 0, -4978.095, -6407.64, -16.1275, 1.053095, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+188, 45179, 0, 1, 169, 0, -5104.792, -6451.588, -38.54901, 1.482594, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+189, 45179, 0, 1, 169, 0, -5082.829, -6486.152, -44.72421, 3.115791, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+190, 45179, 0, 1, 169, 0, -5118.362, -6566.139, -103.5342, 4.764647, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+191, 45179, 0, 1, 169, 0, -5131.342, -6514.134, -74.6078, 4.55593, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+192, 45179, 0, 1, 169, 0, -5115.104, -6407.915, -35.4863, 3.182262, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+193, 45179, 0, 1, 169, 0, -5156.867, -6412.3, -63.52335, 1.570001, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+194, 45179, 0, 1, 169, 0, -5183.329, -6380.687, -85.48421, 4.710612, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+195, 45179, 0, 1, 169, 0, -5156.216, -6339.524, -61.17033, 6.236213, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+196, 45179, 0, 1, 169, 0, -5058.252, -6336.739, -20.85363, 1.418622, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+197, 45179, 0, 1, 169, 0, -5088.845, -6287.772, -18.13096, 3.372806, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+198, 45179, 0, 1, 169, 0, -5163.552, -6281.214, -58.17296, 0.7111935, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+199, 45179, 0, 1, 169, 0, -5120.731, -6244.249, -22.11869, 4.909456, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+200, 45179, 0, 1, 169, 0, -5057.605, -6224.957, -6.54326, 6.280499, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+201, 45179, 0, 1, 169, 0, -5022.556, -6261.122, -7.564455, 5.47293, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+202, 45179, 0, 1, 169, 0, -4998.645, -6311.094, -9.40301, 2.663538, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+203, 45179, 0, 1, 169, 0, -4973.862, -6353.576, -7.267853, 6.148729, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+204, 45179, 0, 1, 169, 0, -4900.643, -6376.871, -8.657864, 0.8997172, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+205, 45179, 0, 1, 169, 0, -4888.911, -6422.791, -19.13046, 1.699766, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+206, 45179, 0, 1, 169, 0, -4839.918, -6402.568, -19.09093, 4.171279, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+207, 45179, 0, 1, 169, 0, -4826.824, -6433.031, -27.64719, 5.404387, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+208, 45179, 0, 1, 169, 0, -4755.655, -6447.575, -25.96413, 0.1683724, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+209, 45179, 0, 1, 169, 0, -4852.952, -6481.619, -58.65791, 1.679119, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+210, 45179, 0, 1, 169, 0, -4780.755, -6514.45, -64.02144, 1.612975, 120, 10, 1), -- Blackscale Myrmidon
(@CGUID+211, 45182, 0, 1, 169, 0, -5013.121, -6515.439, -59.66002, 3.469536, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+212, 45182, 0, 1, 169, 0, -4996.354, -6513.021, -39.1628, 3.300098, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+213, 45182, 0, 1, 169, 0, -4983.426, -6522.273, -67.97115, 3.89471, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+214, 45182, 0, 1, 169, 0, -5061.076, -6435.584, -28.63995, 2.470706, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+215, 45182, 0, 1, 169, 0, -5073.78, -6413.625, -28.9705, 3.078883, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+216, 45182, 0, 1, 169, 0, -5106.088, -6463.164, -41.31903, 1.430817, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+217, 45182, 0, 1, 169, 0, -5047.81, -6414.341, -17.40916, 4.695654, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+218, 45182, 0, 1, 169, 0, -5039.889, -6380.367, -20.32251, 4.40887, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+219, 45182, 0, 1, 169, 0, -5032.801, -6404.697, -24.28627, 1.773059, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+220, 45182, 0, 1, 169, 0, -5141.111, -6479.861, -52.2795, 1.860383, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+221, 45182, 0, 1, 169, 0, -5134.693, -6465.79, -52.8449, 1.229326, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+222, 45182, 0, 1, 169, 0, -5156.046, -6475.646, -66.75235, 4.471229, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+223, 45182, 0, 1, 169, 0, -5131.297, -6418.354, -51.18985, 1.113275, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+224, 45182, 0, 1, 169, 0, -5160.839, -6387.738, -52.2793, 0.1249797, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+225, 45182, 0, 1, 169, 0, -5126.563, -6324.405, -52.13245, 1.570796, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+226, 45182, 0, 1, 169, 0, -5162.682, -6316.993, -58.53597, 4.904778, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+227, 45182, 0, 1, 169, 0, -5133.911, -6298.42, -55.447, 4.206748, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+228, 45182, 0, 1, 169, 0, -5113.354, -6310.522, -29.0166, 2.850987, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+229, 45182, 0, 1, 169, 0, -5148.751, -6269.469, -53.10834, 4.29352, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+230, 45182, 0, 1, 169, 0, -5111.7, -6254.893, -22.0977, 5.734427, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+231, 45182, 0, 1, 169, 0, -5059.858, -6257.576, -9.782834, 3.194503, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+232, 45182, 0, 1, 169, 0, -4999.985, -6259.037, -2.275794, 5.964628, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+233, 45182, 0, 1, 169, 0, -5020.92, -6319.648, -15.1071, 3.587889, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+234, 45182, 0, 1, 169, 0, -4975.583, -6340.968, -5.616241, 5.293905, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+235, 45182, 0, 1, 169, 0, -4938.457, -6340.718, -4.43966, 5.269808, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+236, 45182, 0, 1, 169, 0, -4959.4, -6384.83, -13.61697, 5.386121, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+237, 45182, 0, 1, 169, 0, -4891.859, -6401.261, -15.53361, 5.737289, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+238, 45182, 0, 1, 169, 0, -4923.441, -6405.55, -6.339195, 5.272691, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+239, 45182, 0, 1, 169, 0, -4838.521, -6378.976, -11.87418, 5.126206, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+240, 45182, 0, 1, 169, 0, -4786.602, -6510.793, -65.95833, 5.600965, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+241, 45182, 0, 1, 169, 0, -4884.78, -6488.579, -60.99342, 3.713374, 120, 10, 1), -- Blackscale Seacaller
(@CGUID+242, 45210, 0, 1, 169, 0, -4953.95, -6440.61, 0.2519073, 6.091199, 120, 0, 0), -- Stranded Crewman
(@CGUID+243, 45210, 0, 1, 169, 0, -4966.3, -6451.35, 2.042363, 4.310963, 120, 0, 0), -- Stranded Crewman
(@CGUID+244, 45210, 0, 1, 169, 0, -4937.11, -6446.54, 3.121446, 5.320683, 120, 0, 0), -- Stranded Crewman
(@CGUID+245, 45210, 0, 1, 169, 0, -4971.294, -6436.867, 0.3008443, 0.6401017, 120, 0, 0), -- Stranded Crewman
(@CGUID+246, 45224, 0, 1, 169, 0, -4958.87, -6442.9, 3.590053, 3.769911, 120, 0, 0), -- Lashed to the Mast "Bunny"
(@CGUID+247, 45171, 0, 1, 169, 0, -4966.12, -6441.25, 1.075496, 4.502949, 120, 0, 0); -- Ephram Hardstone

UPDATE `creature_template` SET `flags_extra`=128, `InhabitType`=4 WHERE `entry` IN (45224,45256);

DELETE FROM `creature_template_addon` WHERE `entry` IN (45182,49350,49354,49342);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(45182,0,1,0, '12544'),(49350,0,256,0, '10022'),(49354,0,257,234, ''),(49342,0,256,0, '');

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+15 AND @CGUID+63;
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(@CGUID+15,65536,1,0, '84020 86378'),(@CGUID+16,65536,1,0, '84020 29266'),(@CGUID+17,65536,1,0, '84020 29266'),
(@CGUID+18,65536,1,0, '84020 29266'),(@CGUID+19,65536,1,0, '84020 29266'),(@CGUID+20,65536,1,0, '84020 29266'),
(@CGUID+21,65536,1,0, '84020 86378'),(@CGUID+22,65536,1,0, '84020 29266'),(@CGUID+23,65536,1,0, '84020 29266'),
(@CGUID+24,65536,1,0, '84020 86378'),(@CGUID+25,65536,1,0, '84020 29266'),(@CGUID+26,65536,1,0, '84020 29266'),
(@CGUID+27,65536,1,0, '84020 86378'),(@CGUID+28,65536,1,0, '84020 29266'),(@CGUID+29,65536,1,0, '84020 29266'),
(@CGUID+30,65536,1,0, '84020 86378'),(@CGUID+31,65536,1,0, '84020 86378'),(@CGUID+32,65536,1,0, '84020 29266'),
(@CGUID+33,65536,1,0, '84020 29266'),(@CGUID+34,65536,1,0, '84020 29266'),(@CGUID+35,65536,1,0, '84020 29266'),
(@CGUID+36,65536,1,0, '84020 29266'),(@CGUID+37,65536,1,0, '84020 29266'),(@CGUID+38,65536,1,0, '84020 29266'),
(@CGUID+39,65536,1,0, '84020 86378'),(@CGUID+40,65536,1,0, '84020 29266'),(@CGUID+41,65536,1,0, '84020 29266'),
(@CGUID+42,65536,1,0, '84020 29266'),(@CGUID+43,65536,1,0, '84020 29266'),(@CGUID+44,65536,1,0, '84020 29266'),
(@CGUID+45,65536,1,0, '84020 29266'),(@CGUID+46,65536,1,0, '84020 29266'),(@CGUID+47,65536,1,0, '84020 29266'),
(@CGUID+48,65536,1,0, '84020 29266'),(@CGUID+49,65536,1,0, '84020 29266'),(@CGUID+50,65536,1,0, '84020 29266'),
(@CGUID+51,65536,1,0, '84020 29266'),(@CGUID+52,65536,1,0, '84020 29266'),(@CGUID+53,65536,1,0, '84020 29266'),
(@CGUID+54,65536,1,0, '84020 29266'),(@CGUID+55,65536,1,0, '84020 86378'),(@CGUID+56,65536,1,0, '84020 86378'),
(@CGUID+57,65536,1,0, '84020 29266'),(@CGUID+58,65536,1,0, '84020 29266'),(@CGUID+59,65536,1,0, '84020 29266'),
(@CGUID+60,65536,1,0, '84020 29266'),(@CGUID+61,65536,1,0, '84020 29266'),(@CGUID+62,65536,1,0, '84020 86378'),
(@CGUID+63,65536,1,0, '84020 29266');

DELETE FROM `spell_script_names` WHERE `spell_id`=86378;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (86378,'spell_gen_creature_permanent_feign_death');

-- Spell Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (82405);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,82405,0,31,5,205248,0,0,'','Spell 82405 targets gameobject entry 205248');

-- SAI for Highbank Shaman
SET @ENTRY := 45869;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,600000,600000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highbank Shaman - OOC - Cast 'Water Shield'"),
(@ENTRY,0,1,0,1,0,100,0,1000,8000,15000,18000,11,82405,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highbank Shaman - OOC - Cast 'Cosmetic - Chain Lightning (single)(long pre-cast)'");

-- Highbank, Twilight Highlands, Alliance Zone questing start area
DELETE FROM `phase_area` WHERE `AreaId` IN (5140,5424) AND `PhaseId` IN (169,361);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES 
(5140,361, 'Highbank phase before quest 28598 complete'),
(5140,169, 'Highbank phase after quest 28598 complete'),
(5424,361, 'Obsidian Breakers phase before quest 28598 complete'),
(5424,169, 'Obsidian Breakers phase after quest 28598 complete');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceEntry` IN (5140,5424);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(26,361,5140,0,1, 8,0,28598,0,0,1,0,0,'','Set phase 361 in area 5140 if quest 28598 not rewarded'),
(26,361,5140,0,2,28,0,28598,0,0,1,0,0,'','Set phase 361 in area 5140 if quest 28598 not complete'),
(26,169,5140,0,1, 8,0,28598,0,0,0,0,0,'','Set phase 169 in area 5140 if quest 28598 rewarded'),
(26,169,5140,0,2,28,0,28598,0,0,0,0,0,'','Set phase 169 in area 5140 if quest 28598 complete'),
(26,361,5424,0,1, 8,0,28598,0,0,1,0,0,'','Set phase 361 in area 5140 if quest 28598 not rewarded'),
(26,361,5424,0,2,28,0,28598,0,0,1,0,0,'','Set phase 361 in area 5140 if quest 28598 not complete'),
(26,169,5424,0,1, 8,0,28598,0,0,0,0,0,'','Set phase 169 in area 5140 if quest 28598 rewarded'),
(26,169,5424,0,2,28,0,28598,0,0,0,0,0,'','Set phase 169 in area 5140 if quest 28598 complete');

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+104;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4831.354,`position_y`=-6647.092,`position_z`=9.453926 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4831.354,-6647.092,9.453926,0,0,0,0,100,0),
(@PATH,2,-4822.372,-6638.174,8.984688,0,0,0,0,100,0),
(@PATH,3,-4831.354,-6647.092,9.453926,0,0,0,0,100,0),
(@PATH,4,-4847.052,-6662.674,8.521555,0,0,0,0,100,0),
(@PATH,5,-4865.58,-6678.872,8.742817,0,0,0,0,100,0),
(@PATH,6,-4885.455,-6696.389,9.495326,0,0,0,0,100,0),
(@PATH,7,-4865.58,-6678.872,8.742817,0,0,0,0,100,0),
(@PATH,8,-4847.052,-6662.674,8.521555,0,0,0,0,100,0);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+89;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4844.736,`position_y`=-6675.703,`position_z`=6.371723 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4845.399,`position_y`=-6677.637,`position_z`=6.146143 WHERE `guid`=@CGUID+90;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+90);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+90,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4844.736,-6675.703,6.371723,0,0,0,0,100,0),
(@PATH,2,-4812.865,-6687.143,5.097479,0,0,0,0,100,0),
(@PATH,3,-4788.882,-6696.946,4.453924,0,0,0,0,100,0),
(@PATH,4,-4772.415,-6714.198,4.449464,0,0,0,0,100,0),
(@PATH,5,-4753.194,-6735.156,5.183077,0,0,0,0,100,0),
(@PATH,6,-4772.415,-6714.198,4.449464,0,0,0,0,100,0),
(@PATH,7,-4788.882,-6696.946,4.453924,0,0,0,0,100,0),
(@PATH,8,-4812.865,-6687.143,5.097479,0,0,0,0,100,0),
(@PATH,9,-4844.736,-6675.703,6.371723,0,0,0,0,100,0),
(@PATH,10,-4859.772,-6663.365,8.605051,0,0,0,0,100,0),
(@PATH,11,-4866.864,-6654.434,10.85385,0,0,0,0,100,0),
(@PATH,12,-4879.003,-6639.686,10.85162,0,0,0,0,100,0),
(@PATH,13,-4866.943,-6654.337,10.85399,0,0,0,0,100,0),
(@PATH,14,-4859.375,-6663.541,8.605051,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+90,2,90,2,5,12);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+91;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4829.724,`position_y`=-6701.387,`position_z`=5.203925 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4829.152,`position_y`=-6704.967,`position_z`=5.165596 WHERE `guid`=@CGUID+92;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+92);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+92,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4829.724,-6701.387,5.203925,0,0,0,0,100,0),
(@PATH,2,-4820.585,-6711.351,5.203925,0,0,0,0,100,0),
(@PATH,3,-4829.724,-6701.387,5.203925,0,0,0,0,100,0),
(@PATH,4,-4840.894,-6694.573,4.462788,0,0,0,0,100,0),
(@PATH,5,-4856.132,-6699.838,4.462788,0,0,0,0,100,0),
(@PATH,6,-4874.393,-6714.79,4.677069,0,0,0,0,100,0),
(@PATH,7,-4883.927,-6723.188,4.552069,0,0,0,0,100,0),
(@PATH,8,-4874.393,-6714.79,4.677069,0,0,0,0,100,0),
(@PATH,9,-4856.132,-6699.838,4.462788,0,0,0,0,100,0),
(@PATH,10,-4840.894,-6694.573,4.462788,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+92,2,90,2,2,7);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+95;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4942.741,`position_y`=-6752.318,`position_z`=0.8641129 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4941.295,`position_y`=-6753.615,`position_z`=0.8641129 WHERE `guid`=@CGUID+96;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+96);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+96,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4942.741,-6752.318,0.8641129,0,0,0,0,100,0),
(@PATH,2,-4932.917,-6746.643,1.33007,0,0,0,0,100,0),
(@PATH,3,-4926.818,-6742.708,5.499268,0,0,0,0,100,0),
(@PATH,4,-4918.39,-6736.981,5.506974,0,0,0,0,100,0),
(@PATH,5,-4912.44,-6732.709,1.218719,0,0,0,0,100,0),
(@PATH,6,-4902.538,-6725.488,0.6599402,0,0,0,0,100,0),
(@PATH,7,-4893.75,-6718.75,4.802069,0,0,0,0,100,0),
(@PATH,8,-4891.918,-6710.278,5.177069,0,0,0,0,100,0),
(@PATH,9,-4903.537,-6698.389,5.066396,0,0,0,0,100,0),
(@PATH,10,-4911.208,-6692.064,4.923329,0,0,0,0,100,0),
(@PATH,11,-4903.537,-6698.389,5.066396,0,0,0,0,100,0),
(@PATH,12,-4891.918,-6710.278,5.177069,0,0,0,0,100,0),
(@PATH,13,-4893.681,-6719.577,4.765448,0,0,0,0,100,0),
(@PATH,14,-4902.229,-6725.37,0.8312815,0,0,0,0,100,0),
(@PATH,15,-4912.288,-6732.601,1.135311,0,0,0,0,100,0),
(@PATH,16,-4918.236,-6736.877,5.478069,0,0,0,0,100,0),
(@PATH,17,-4926.818,-6742.708,5.499268,0,0,0,0,100,0),
(@PATH,18,-4932.897,-6746.656,1.334893,0,0,0,0,100,0),
(@PATH,19,-4942.05,-6752.148,0.8669548,0,0,0,0,100,0),
(@PATH,20,-4950.085,-6756.993,4.960552,0,0,0,0,100,0),
(@PATH,21,-4962.073,-6764.293,5.762395,0,0,0,0,100,0),
(@PATH,22,-4950.085,-6756.993,4.960552,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+96,2,90,2,10,21);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+98;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4805.575,`position_y`=-6734.543,`position_z`=9.477418 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4804.171,`position_y`=-6735.854,`position_z`=9.413300 WHERE `guid`=@CGUID+99;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+99);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+99,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4805.575,-6734.543,9.477418,0,0,0,0,100,0),
(@PATH,2,-4791.366,-6724.941,9.449464,0,0,0,0,100,0),
(@PATH,3,-4805.575,-6734.543,9.477418,0,0,0,0,100,0),
(@PATH,4,-4825.314,-6736.224,9.477418,0,0,0,0,100,0),
(@PATH,5,-4848.965,-6737.738,9.509106,0,0,0,0,100,0),
(@PATH,6,-4861.397,-6745.403,9.509106,0,0,0,0,100,0),
(@PATH,7,-4848.965,-6737.738,9.509106,0,0,0,0,100,0),
(@PATH,8,-4825.314,-6736.224,9.477418,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+99,2,90,2,2,6);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+107;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4810.429,`position_y`=-6649.76,`position_z`=4.453927 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4809.291,`position_y`=-6650.98,`position_z`=4.349684 WHERE `guid`=@CGUID+109;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+109);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+109,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4810.429,-6649.76,4.453927,0,0,0,0,100,0),
(@PATH,2,-4800.365,-6638.535,4.453927,0,0,0,0,100,0),
(@PATH,3,-4776.257,-6640.082,4.453927,0,0,0,0,100,0),
(@PATH,4,-4757.394,-6654.349,4.879866,0,0,0,0,100,0),
(@PATH,5,-4755.499,-6674.507,4.703925,0,0,0,0,100,0),
(@PATH,6,-4764.674,-6687.894,4.850165,0,0,0,0,100,0),
(@PATH,7,-4782.018,-6699.934,4.453924,0,0,0,0,100,0),
(@PATH,8,-4803.651,-6699.425,4.453925,0,0,0,0,100,0),
(@PATH,9,-4822.853,-6692.899,4.453925,0,0,0,0,100,0),
(@PATH,10,-4803.651,-6699.425,4.453925,0,0,0,0,100,0),
(@PATH,11,-4782.018,-6699.934,4.453924,0,0,0,0,100,0),
(@PATH,12,-4764.674,-6687.894,4.850165,0,0,0,0,100,0),
(@PATH,13,-4755.499,-6674.507,4.703925,0,0,0,0,100,0),
(@PATH,14,-4757.394,-6654.349,4.879866,0,0,0,0,100,0),
(@PATH,15,-4776.257,-6640.082,4.453927,0,0,0,0,100,0),
(@PATH,16,-4800.365,-6638.535,4.453927,0,0,0,0,100,0),
(@PATH,17,-4810.429,-6649.76,4.453927,0,0,0,0,100,0),
(@PATH,18,-4821.266,-6666.986,4.592597,0,0,0,0,100,0),
(@PATH,19,-4841.323,-6682.993,5.087299,0,0,0,0,100,0),
(@PATH,20,-4859.896,-6695.778,4.781879,0,0,0,0,100,0),
(@PATH,21,-4879.359,-6711.797,4.659491,0,0,0,0,100,0),
(@PATH,22,-4859.896,-6695.778,4.781879,0,0,0,0,100,0),
(@PATH,23,-4841.323,-6682.993,5.087299,0,0,0,0,100,0),
(@PATH,24,-4821.266,-6666.986,4.592597,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+109,2,90,2,9,21);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+117;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4827.467,`position_y`=-6616.877,`position_z`=8.699944 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4826.091,`position_y`=-6615.888,`position_z`=8.375416 WHERE `guid`=@CGUID+118;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+118);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+118,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4827.467,-6616.877,8.699944,0,0,0,0,100,0),
(@PATH,2,-4841.932,-6603.295,9.491281,0,0,0,0,100,0),
(@PATH,3,-4855.537,-6591.938,9.492112,0,0,0,0,100,0),
(@PATH,4,-4855.488,-6583.986,9.492112,0,0,0,0,100,0),
(@PATH,5,-4846.953,-6580.429,9.492112,0,0,0,0,100,0),
(@PATH,6,-4835.45,-6585.078,9.492112,0,0,0,0,100,0),
(@PATH,7,-4812.111,-6595.083,9.486526,0,0,0,0,100,0),
(@PATH,8,-4799.677,-6601.488,9.430349,0,0,0,0,100,0),
(@PATH,9,-4812.111,-6595.083,9.486526,0,0,0,0,100,0),
(@PATH,10,-4835.45,-6585.078,9.492112,0,0,0,0,100,0),
(@PATH,11,-4846.953,-6580.429,9.492112,0,0,0,0,100,0),
(@PATH,12,-4855.488,-6583.986,9.492112,0,0,0,0,100,0),
(@PATH,13,-4855.537,-6591.938,9.492112,0,0,0,0,100,0),
(@PATH,14,-4841.932,-6603.295,9.491281,0,0,0,0,100,0),
(@PATH,15,-4827.467,-6616.877,8.699944,0,0,0,0,100,0),
(@PATH,16,-4811.299,-6635.024,5.606759,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+118,2,90,2,8,16);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+121;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4802.412,`position_y`=-6630.389,`position_z`=4.89843 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4800.862,`position_y`=-6628.632,`position_z`=4.97909 WHERE `guid`=@CGUID+122;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+122);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+122,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4802.412,-6630.389,4.89843,0,0,0,0,100,0),
(@PATH,2,-4821.561,-6611.309,7.657464,0,0,0,0,100,0),
(@PATH,3,-4802.412,-6630.389,4.89843,0,0,0,0,100,0),
(@PATH,4,-4778.92,-6632.299,4.430349,0,0,0,0,100,0),
(@PATH,5,-4764.863,-6643.139,4.840559,0,0,0,0,100,0),
(@PATH,6,-4746.21,-6659.58,5.030501,0,0,0,0,100,0),
(@PATH,7,-4737.21,-6665.137,5.079817,0,0,0,0,100,0),
(@PATH,8,-4746.21,-6659.58,5.030501,0,0,0,0,100,0),
(@PATH,9,-4764.863,-6643.139,4.840559,0,0,0,0,100,0),
(@PATH,10,-4778.92,-6632.299,4.430349,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+122,2,90,2,2,7);

-- Pathing for Highbank Guardsman Entry: 49342 'TDB FORMAT' 
SET @NPC := @CGUID+126;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4999.344,`position_y`=-6721.851,`position_z`=5.03057 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4998.414,`position_y`=-6720.321,`position_z`=5.03057 WHERE `guid`=@CGUID+129;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@CGUID+129);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,256,0, ''),(@CGUID+129,@PATH,0,0,256,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4999.344,-6721.851,5.03057,0,0,0,0,100,0),
(@PATH,2,-5012.5,-6715.625,5.228971,0,0,0,0,100,0),
(@PATH,3,-4999.344,-6721.851,5.03057,0,0,0,0,100,0),
(@PATH,4,-4984.026,-6730.647,5.224112,0,0,0,0,100,0),
(@PATH,5,-4974.79,-6740.434,5.197261,0,0,0,0,100,0),
(@PATH,6,-4967.141,-6754.606,4.469234,0,0,0,0,100,0),
(@PATH,7,-4974.79,-6740.434,5.197261,0,0,0,0,100,0),
(@PATH,8,-4984.026,-6730.647,5.224112,0,0,0,0,100,0);
-- Highbank Guardsman formation
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@CGUID+129,2,90,2,2,6);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+73;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4752.351,`position_y`=-6768.917,`position_z`=17.66694 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4752.351,-6768.917,17.66694,0,0,0,0,100,0),
(@PATH,2,-4777.759,-6770.432,17.66796,0,0,0,0,100,0),
(@PATH,3,-4795.939,-6771.488,17.67006,0,0,0,0,100,0),
(@PATH,4,-4806.658,-6772.037,17.67183,0,0,0,0,100,0),
(@PATH,5,-4795.939,-6771.488,17.67006,0,0,0,0,100,0),
(@PATH,6,-4777.759,-6770.432,17.66796,0,0,0,0,100,0);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+74;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4868.479,`position_y`=-6607.193,`position_z`=31.9134 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4868.479,-6607.193,31.9134,0,0,0,0,100,0),
(@PATH,2,-4861,-6615.479,31.91307,0,0,0,0,100,0),
(@PATH,3,-4856.319,-6620.979,31.91303,0,0,0,0,100,0),
(@PATH,4,-4861,-6615.479,31.91307,0,0,0,0,100,0),
(@PATH,5,-4868.479,-6607.193,31.9134,0,0,0,0,100,0),
(@PATH,6,-4875.474,-6598.662,31.91329,0,0,0,0,100,0);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+75;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4894.912,`position_y`=-6654.983,`position_z`=31.91327 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4894.912,-6654.983,31.91327,0,0,0,0,100,0),
(@PATH,2,-4902.002,-6646.939,31.91708,0,0,0,0,100,0),
(@PATH,3,-4908.319,-6639.439,31.91735,0,0,0,0,100,0),
(@PATH,4,-4913.731,-6632.486,31.91758,0,0,0,0,100,0),
(@PATH,5,-4908.319,-6639.439,31.91735,0,0,0,0,100,0),
(@PATH,6,-4902.002,-6646.939,31.91708,0,0,0,0,100,0);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+76;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4872.212,`position_y`=-6607.646,`position_z`=31.9121 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4872.212,-6607.646,31.9121,0,0,0,0,100,0),
(@PATH,2,-4863.476,-6618.691,31.91529,0,0,0,0,100,0),
(@PATH,3,-4856.575,-6626.837,31.91225,0,0,0,0,100,0),
(@PATH,4,-4855.668,-6635.78,31.91225,0,0,0,0,100,0),
(@PATH,5,-4867.497,-6646.087,31.91334,0,0,0,0,100,0),
(@PATH,6,-4878.448,-6655,31.91417,0,0,0,0,100,0),
(@PATH,7,-4886.877,-6661.175,31.91277,0,0,0,0,100,0),
(@PATH,8,-4892.356,-6660.978,31.91396,0,0,0,0,100,0),
(@PATH,9,-4898.309,-6665.531,31.91474,0,0,0,0,100,0),
(@PATH,10,-4892.356,-6660.978,31.91396,0,0,0,0,100,0),
(@PATH,11,-4886.877,-6661.175,31.91277,0,0,0,0,100,0),
(@PATH,12,-4878.448,-6655,31.91417,0,0,0,0,100,0),
(@PATH,13,-4867.497,-6646.087,31.91334,0,0,0,0,100,0),
(@PATH,14,-4855.668,-6635.78,31.91225,0,0,0,0,100,0),
(@PATH,15,-4856.56,-6626.986,31.91182,0,0,0,0,100,0),
(@PATH,16,-4863.476,-6618.691,31.91529,0,0,0,0,100,0),
(@PATH,17,-4872.212,-6607.646,31.9121,0,0,0,0,100,0),
(@PATH,18,-4882.484,-6595.295,31.91267,0,0,0,0,100,0);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+77;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4814.499,`position_y`=-6574.359,`position_z`=17.34797 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4814.499,-6574.359,17.34797,0,0,0,0,100,0),
(@PATH,2,-4830.95,-6568.486,17.34797,0,0,0,0,100,0),
(@PATH,3,-4849.655,-6562.24,17.34797,0,0,0,0,100,0),
(@PATH,4,-4867.071,-6565.984,17.31609,0,0,0,0,100,0),
(@PATH,5,-4873.108,-6571.03,17.31152,0,0,0,0,100,0),
(@PATH,6,-4867.071,-6565.984,17.31609,0,0,0,0,100,0),
(@PATH,7,-4849.655,-6562.24,17.34797,0,0,0,0,100,0),
(@PATH,8,-4830.95,-6568.486,17.34797,0,0,0,0,100,0),
(@PATH,9,-4814.499,-6574.359,17.34797,0,0,0,0,100,0),
(@PATH,10,-4796.825,-6580.422,17.34795,0,0,0,0,100,0);

-- Pathing for Highbank Marksman Entry: 49341 'TDB FORMAT' 
SET @NPC := @CGUID+81;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4899.559,`position_y`=-6656.002,`position_z`=31.917 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4899.559,-6656.002,31.917,0,0,0,0,100,0),
(@PATH,2,-4906.535,-6647.281,31.9173,0,0,0,0,100,0),
(@PATH,3,-4921.559,-6630.184,31.91302,0,0,0,0,100,0),
(@PATH,4,-4920.073,-6622.172,31.91601,0,0,0,0,100,0),
(@PATH,5,-4908.894,-6612.103,31.91398,0,0,0,0,100,0),
(@PATH,6,-4894.991,-6600.474,31.91323,0,0,0,0,100,0),
(@PATH,7,-4908.894,-6612.103,31.91398,0,0,0,0,100,0),
(@PATH,8,-4920.021,-6621.894,31.91285,0,0,0,0,100,0),
(@PATH,9,-4921.559,-6630.184,31.91302,0,0,0,0,100,0),
(@PATH,10,-4906.535,-6647.281,31.9173,0,0,0,0,100,0);

-- Pathing for Tidebreaker Sailor Entry: 49350 'TDB FORMAT' 
SET @NPC := @CGUID+139;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4916.596,`position_y`=-6758.026,`position_z`=15.16407 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '10022');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4916.596,-6758.026,15.16407,0,0,0,0,100,0),
(@PATH,2,-4912.545,-6760.342,15.27375,0,0,0,0,100,0),
(@PATH,3,-4907.95,-6757.035,15.26457,0,0,0,0,100,0),
(@PATH,4,-4908.052,-6752.005,15.04875,0,0,0,0,100,0),
(@PATH,5,-4913.198,-6744.113,5.743296,0,0,0,0,100,0),
(@PATH,6,-4917.557,-6740.516,5.618814,0,0,0,0,100,0),
(@PATH,7,-4921.772,-6733.608,5.400787,0,0,0,0,100,0),
(@PATH,8,-4924.233,-6725.67,5.408527,0,0,0,0,100,0),
(@PATH,9,-4931.953,-6720.342,5.764146,0,0,0,0,100,0),
(@PATH,10,-4937.172,-6723.889,5.802237,0,0,0,0,100,0),
(@PATH,11,-4935.738,-6732.66,5.41413,0,0,0,0,100,0),
(@PATH,12,-4927.858,-6738.804,5.406329,0,0,0,0,100,0),
(@PATH,13,-4923.878,-6745.213,5.609965,0,0,0,0,100,0),
(@PATH,14,-4922.071,-6750.428,5.752007,0,0,0,0,100,0);

-- Pathing for Stranded Crewman Entry: 45210 'TDB FORMAT' 
SET @NPC := @CGUID+242;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4953.95,`position_y`=-6440.61,`position_z`=0.2519073 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4953.95,-6440.61,0.2519073,3.001966,8000,0,491,100,0),
(@PATH,2,-4953.95,-6440.61,0.2519073,6.091199,4000,0,0,100,0); 

-- Pathing for Stranded Crewman Entry: 45210 'TDB FORMAT' 
SET @NPC := @CGUID+243;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4966.3,`position_y`=-6451.35,`position_z`=2.042363 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4966.3,-6451.35,2.042363,1.117011,15000,0,0,100,0),
(@PATH,2,-4966.3,-6451.35,2.042363,4.310963,15000,0,0,100,0);

-- Pathing for Stranded Crewman Entry: 45210 'TDB FORMAT' 
SET @NPC := @CGUID+244;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4940.24,`position_y`=-6441.02,`position_z`=2.360719 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4940.24,-6441.02,2.360719,0,0,0,0,100,0),
(@PATH,2,-4941.71,-6439.77,2.094354,0,6000,0,0,100,0),
(@PATH,3,-4938.75,-6435.98,2.411006,0,0,0,0,100,0),
(@PATH,4,-4938.75,-6435.98,2.411006,1.308997,10000,0,491,100,0),
(@PATH,5,-4938.83,-6444.07,2.730427,0,0,0,0,100,0),
(@PATH,6,-4937.11,-6446.54,3.121446,0,6000,0,492,100,0);

-- Pathing for Stranded Crewman Entry: 45210 'TDB FORMAT' 
SET @NPC := @CGUID+245;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4971.13,`position_y`=-6436.74,`position_z`=0.303665 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4971.13,-6436.74,0.303665,0,0,0,0,100,0),
(@PATH,2,-4974.63,-6439.35,0.2362317,0,0,0,0,100,0),
(@PATH,3,-4974.63,-6439.35,0.2362317,5.532694,4000,0,0,100,0),
(@PATH,4,-4969.66,-6435.65,0.3125727,0,0,0,0,100,0),
(@PATH,5,-4967.47,-6433.57,0.2708609,0,0,0,0,100,0),
(@PATH,6,-4967.47,-6433.57,0.2708609,2.007129,16000,0,0,100,0);

DELETE FROM `waypoint_scripts` WHERE `id` IN (491,492);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES
(491,1,1,432,0,0,0,0,0,894),
(491,4,1,432,0,0,0,0,0,895),
(492,2,1,22,0,0,0,0,0,896);

DELETE FROM `npc_vendor` WHERE `entry` IN (49695, 49726, 49729, 50381, 50382, 50134, 49733, 49702, 49703, 50386, 49704, 49705, 49707, 49714, 50458, 49723);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`, `VerifiedBuild`) VALUES
-- 49695
(49695, 2901, 1, 0, 0, 1, 20574), -- 2901
(49695, 5956, 2, 0, 0, 1, 20574), -- 5956
(49695, 2880, 3, 0, 0, 1, 20574), -- 2880
(49695, 3466, 4, 0, 0, 1, 20574), -- 3466
(49695, 18567, 5, 0, 0, 1, 20574), -- 18567
(49695, 3857, 6, 0, 0, 1, 20574), -- 3857
-- 49726
(49726, 2901, 1, 0, 0, 1, 20574), -- 2901
(49726, 5956, 2, 0, 0, 1, 20574), -- 5956
(49726, 2880, 3, 0, 0, 1, 20574), -- 2880
(49726, 3466, 4, 0, 0, 1, 20574), -- 3466
(49726, 18567, 5, 0, 0, 1, 20574), -- 18567
(49726, 3857, 6, 0, 0, 1, 20574), -- 3857
-- 49729
(49729, 2723, 1, 0, 0, 1, 20574), -- 2723
(49729, 2593, 2, 0, 0, 1, 20574), -- 2593
(49729, 2596, 3, 0, 0, 1, 20574), -- 2596
(49729, 2594, 4, 0, 0, 1, 20574), -- 2594
(49729, 2595, 5, 0, 0, 1, 20574), -- 2595
(49729, 83095, 6, 0, 0, 1, 20574), -- 83095
(49729, 82343, 7, 0, 0, 1, 20574), -- 82343
(49729, 83094, 8, 0, 0, 1, 20574), -- 83094
(49729, 82344, 9, 0, 0, 1, 20574), -- 82344
(49729, 2511, 10, 0, 0, 1, 20574), -- 2511
(49729, 3023, 11, 0, 0, 1, 20574), -- 3023
(49729, 3024, 12, 0, 0, 1, 20574), -- 3024
(49729, 3025, 13, 0, 0, 1, 20574), -- 3025
-- 50381
(50381, 52980, 1, 0, 3330, 1, 20574), -- 52980
(50381, 67080, 2, 0, 3330, 1, 20574), -- 67080
(50381, 67065, 3, 0, 3330, 1, 20574), -- 67065
(50381, 67054, 4, 0, 3330, 1, 20574), -- 67054
(50381, 67093, 5, 0, 3330, 1, 20574), -- 67093
(50381, 67066, 6, 0, 3330, 1, 20574), -- 67066
(50381, 67081, 7, 0, 3330, 1, 20574), -- 67081
(50381, 67092, 8, 0, 3330, 1, 20574), -- 67092
(50381, 67055, 9, 0, 3330, 1, 20574), -- 67055
(50381, 67076, 10, 0, 3330, 1, 20574), -- 67076
(50381, 67060, 11, 0, 3330, 1, 20574), -- 67060
(50381, 67046, 12, 0, 3330, 1, 20574), -- 67046
(50381, 67087, 13, 0, 3330, 1, 20574), -- 67087
(50381, 67048, 14, 0, 3330, 1, 20574), -- 67048
(50381, 67077, 15, 0, 3330, 1, 20574), -- 67077
(50381, 67089, 16, 0, 3330, 1, 20574), -- 67089
(50381, 67062, 17, 0, 3330, 1, 20574), -- 67062
(50381, 67064, 18, 0, 3330, 1, 20574), -- 67064
(50381, 67063, 19, 0, 3330, 1, 20574), -- 67063
(50381, 67049, 20, 0, 3330, 1, 20574), -- 67049
(50381, 67090, 21, 0, 3330, 1, 20574), -- 67090
(50381, 67053, 22, 0, 3330, 1, 20574), -- 67053
(50381, 67091, 23, 0, 3330, 1, 20574), -- 67091
(50381, 67079, 24, 0, 3330, 1, 20574), -- 67079
(50381, 67078, 25, 0, 3330, 1, 20574), -- 67078
(50381, 67044, 26, 0, 3330, 1, 20574), -- 67044
(50381, 67058, 27, 0, 3330, 1, 20574), -- 67058
(50381, 67042, 28, 0, 3330, 1, 20574), -- 67042
(50381, 67075, 29, 0, 3330, 1, 20574), -- 67075
(50381, 67056, 30, 0, 3330, 1, 20574), -- 67056
(50381, 67086, 31, 0, 3330, 1, 20574), -- 67086
(50381, 67085, 32, 0, 3330, 1, 20574), -- 67085
(50381, 67074, 33, 0, 3330, 1, 20574), -- 67074
(50381, 67095, 34, 0, 3330, 1, 20574), -- 67095
(50381, 67070, 35, 0, 3330, 1, 20574), -- 67070
(50381, 67084, 36, 0, 3330, 1, 20574), -- 67084
(50381, 67094, 37, 0, 3330, 1, 20574), -- 67094
(50381, 67073, 38, 0, 3330, 1, 20574), -- 67073
(50381, 67100, 39, 0, 3330, 1, 20574), -- 67100
(50381, 68193, 40, 0, 3330, 1, 20574), -- 68193
(50381, 71721, 41, 0, 3330, 1, 20574), -- 71721
(50381, 67068, 42, 0, 3330, 1, 20574), -- 67068
(50381, 67082, 43, 0, 3330, 1, 20574), -- 67082
(50381, 67072, 44, 0, 3330, 1, 20574), -- 67072
(50381, 67083, 45, 0, 3330, 1, 20574), -- 67083
(50381, 67096, 46, 0, 3330, 1, 20574), -- 67096
-- 50382
(50382, 66117, 1, 0, 3312, 1, 20574), -- 66117
(50382, 66118, 2, 0, 3312, 1, 20574), -- 66118
(50382, 66125, 3, 0, 3312, 1, 20574), -- 66125
(50382, 66126, 4, 0, 3312, 1, 20574), -- 66126
(50382, 66103, 5, 0, 3312, 1, 20574), -- 66103
(50382, 66119, 6, 0, 3312, 1, 20574), -- 66119
(50382, 66107, 7, 0, 3312, 1, 20574), -- 66107
(50382, 66105, 8, 0, 3312, 1, 20574), -- 66105
(50382, 66109, 9, 0, 3312, 1, 20574), -- 66109
(50382, 66127, 10, 0, 3312, 1, 20574), -- 66127
(50382, 66120, 11, 0, 3313, 1, 20574), -- 66120
(50382, 67603, 12, 0, 3313, 1, 20574), -- 67603
(50382, 67606, 13, 0, 3314, 1, 20574), -- 67606
(50382, 66113, 14, 0, 3313, 1, 20574), -- 66113
(50382, 66106, 15, 0, 3313, 1, 20574), -- 66106
(50382, 66111, 16, 0, 3313, 1, 20574), -- 66111
(50382, 66104, 17, 0, 3313, 1, 20574), -- 66104
(50382, 66108, 18, 0, 3313, 1, 20574), -- 66108
(50382, 66128, 19, 0, 3313, 1, 20574), -- 66128
(50382, 66121, 20, 0, 3313, 1, 20574), -- 66121
(50382, 66115, 21, 0, 3313, 1, 20574), -- 66115
(50382, 66112, 22, 0, 3313, 1, 20574), -- 66112
(50382, 66114, 23, 0, 3313, 1, 20574), -- 66114
(50382, 66110, 24, 0, 3313, 1, 20574), -- 66110
(50382, 66116, 25, 0, 3313, 1, 20574), -- 66116
(50382, 66129, 26, 0, 3313, 1, 20574), -- 66129
(50382, 66124, 27, 0, 3314, 1, 20574), -- 66124
(50382, 66123, 28, 0, 3314, 1, 20574), -- 66123
(50382, 66122, 29, 0, 3314, 1, 20574), -- 66122
(50382, 66100, 30, 0, 3314, 1, 20574), -- 66100
(50382, 66132, 31, 0, 3314, 1, 20574), -- 66132
(50382, 66131, 32, 0, 3314, 1, 20574), -- 66131
(50382, 66130, 33, 0, 3314, 1, 20574), -- 66130
(50382, 66101, 34, 0, 3314, 1, 20574), -- 66101
-- 50134
(50134, 67312, 1, 0, 3326, 1, 20574), -- 67312
(50134, 64411, 3, 0, 3016, 1, 20574), -- 64411
(50134, 64412, 4, 0, 3016, 1, 20574), -- 64412
(50134, 52738, 5, 0, 3016, 1, 20574), -- 52738
(50134, 64413, 6, 0, 3016, 1, 20574), -- 64413
(50134, 52740, 7, 0, 3016, 1, 20574), -- 52740
(50134, 52739, 8, 0, 3016, 1, 20574), -- 52739
(50134, 52737, 9, 0, 3016, 1, 20574), -- 52737
(50134, 64414, 10, 0, 3016, 1, 20574), -- 64414
(50134, 64415, 11, 0, 3016, 1, 20574), -- 64415
(50134, 52736, 12, 0, 3017, 1, 20574), -- 52736
(50134, 52733, 13, 0, 3017, 1, 20574), -- 52733
(50134, 52735, 14, 0, 3017, 1, 20574), -- 52735
-- 49733
(49733, 64670, 1, 0, 0, 1, 20574), -- 64670
(49733, 63388, 2, 0, 0, 1, 20574), -- 63388
(49733, 79249, 3, 0, 0, 1, 20574), -- 79249
-- 49702
(49702, 59496, 1, 0, 3306, 1, 20574), -- 59496
(49702, 59493, 2, 0, 3307, 1, 20574), -- 59493
(49702, 59491, 3, 0, 3305, 1, 20574), -- 59491
(49702, 59480, 4, 0, 3308, 1, 20574), -- 59480
(49702, 59479, 5, 0, 3311, 1, 20574), -- 59479
(49702, 59478, 6, 0, 3311, 1, 20574), -- 59478
(49702, 59477, 7, 0, 3392, 1, 20574), -- 59477
(49702, 59489, 8, 0, 3310, 1, 20574), -- 59489
(49702, 68660, 9, 0, 989, 1, 20574), -- 68660
(49702, 5956, 10, 0, 0, 1, 20574), -- 5956
(49702, 2901, 11, 0, 0, 1, 20574), -- 2901
(49702, 90146, 12, 0, 0, 1, 20574), -- 90146
(49702, 4399, 13, 0, 0, 1, 20574), -- 4399
(49702, 4400, 14, 0, 0, 1, 20574), -- 4400
(49702, 40533, 15, 0, 0, 1, 20574), -- 40533
(49702, 39684, 16, 0, 0, 1, 20574), -- 39684
(49702, 2880, 17, 0, 0, 1, 20574), -- 2880
(49702, 3466, 18, 0, 0, 1, 20574), -- 3466
(49702, 39354, 19, 0, 0, 1, 20574), -- 39354
(49702, 10647, 20, 0, 0, 1, 20574), -- 10647
(49702, 4470, 21, 0, 0, 1, 20574), -- 4470
(49702, 30746, 22, 0, 0, 1, 20574), -- 30746
(49702, 3857, 23, 0, 0, 1, 20574), -- 3857
(49702, 20815, 24, 0, 0, 1, 20574), -- 20815
-- 49703
(49703, 3371, 1, 0, 0, 1, 20574), -- 3371
(49703, 39505, 2, 0, 0, 1, 20574), -- 39505
(49703, 39489, 3, 0, 0, 1, 20574), -- 39489
(49703, 39354, 4, 0, 0, 1, 20574), -- 39354
(49703, 64670, 5, 0, 0, 1, 20574), -- 64670
(49703, 63388, 6, 0, 0, 1, 20574), -- 63388
(49703, 62323, 7, 0, 0, 1, 20574), -- 62323
(49703, 68047, 8, 0, 0, 1, 20574), -- 68047
(49703, 67348, 9, 0, 0, 1, 20574), -- 67348
(49703, 67319, 10, 0, 0, 1, 20574), -- 67319
(49703, 67335, 11, 0, 0, 1, 20574), -- 67335
-- 50386
(50386, 68199, 1, 0, 2988, 1, 20574), -- 68199
(50386, 54600, 2, 0, 2988, 1, 20574), -- 54600
(50386, 54599, 3, 0, 2988, 1, 20574), -- 54599
(50386, 54593, 4, 0, 2988, 1, 20574), -- 54593
(50386, 54594, 5, 0, 2988, 1, 20574), -- 54594
(50386, 54595, 6, 0, 2988, 1, 20574), -- 54595
(50386, 54596, 7, 0, 2988, 1, 20574), -- 54596
(50386, 54597, 8, 0, 2988, 1, 20574), -- 54597
(50386, 54598, 9, 0, 2988, 1, 20574), -- 54598
(50386, 54604, 10, 0, 2989, 1, 20574), -- 54604
(50386, 54601, 11, 0, 2989, 1, 20574), -- 54601
(50386, 54603, 12, 0, 2989, 1, 20574), -- 54603
(50386, 54602, 13, 0, 2989, 1, 20574), -- 54602
(50386, 54605, 14, 0, 2989, 1, 20574), -- 54605
-- 49704
(49704, 58280, 1, 0, 0, 1, 20574), -- 58280
(49704, 58268, 2, 0, 0, 1, 20574), -- 58268
(49704, 58269, 3, 0, 0, 1, 20574), -- 58269
(49704, 58277, 4, 0, 0, 1, 20574), -- 58277
(49704, 58262, 5, 0, 0, 1, 20574), -- 58262
(49704, 58263, 6, 0, 0, 1, 20574), -- 58263
(49704, 58274, 7, 0, 0, 1, 20574), -- 58274
(49704, 58256, 8, 0, 0, 1, 20574), -- 58256
(49704, 58257, 9, 0, 0, 1, 20574), -- 58257
-- 49705
(49705, 2320, 1, 0, 0, 1, 20574), -- 2320
(49705, 2321, 2, 0, 0, 1, 20574), -- 2321
(49705, 4291, 3, 0, 0, 1, 20574), -- 4291
(49705, 8343, 4, 0, 0, 1, 20574), -- 8343
(49705, 14341, 5, 0, 0, 1, 20574), -- 14341
(49705, 38426, 6, 0, 0, 1, 20574), -- 38426
(49705, 2324, 7, 0, 0, 1, 20574), -- 2324
(49705, 2604, 8, 0, 0, 1, 20574), -- 2604
(49705, 6260, 9, 0, 0, 1, 20574), -- 6260
(49705, 2605, 10, 0, 0, 1, 20574), -- 2605
(49705, 4341, 11, 0, 0, 1, 20574), -- 4341
(49705, 4340, 12, 0, 0, 1, 20574), -- 4340
(49705, 6261, 13, 0, 0, 1, 20574), -- 6261
(49705, 2325, 14, 0, 0, 1, 20574), -- 2325
(49705, 4342, 15, 0, 0, 1, 20574), -- 4342
(49705, 10290, 16, 0, 0, 1, 20574), -- 10290
-- 49707
(49707, 20815, 1, 0, 0, 1, 20574), -- 20815
(49707, 52188, 2, 0, 0, 1, 20574), -- 52188
-- 49714
(49714, 7005, 1, 0, 0, 1, 20574), -- 7005
(49714, 4289, 2, 0, 0, 1, 20574), -- 4289
(49714, 2320, 3, 0, 0, 1, 20574), -- 2320
(49714, 2321, 4, 0, 0, 1, 20574), -- 2321
(49714, 4291, 5, 0, 0, 1, 20574), -- 4291
(49714, 8343, 6, 0, 0, 1, 20574), -- 8343
(49714, 14341, 7, 0, 0, 1, 20574), -- 14341
(49714, 38426, 8, 0, 0, 1, 20574), -- 38426
(49714, 2325, 9, 0, 0, 1, 20574), -- 2325
(49714, 6260, 10, 0, 0, 1, 20574), -- 6260
(49714, 2604, 11, 0, 0, 1, 20574), -- 2604
(49714, 2605, 12, 0, 0, 1, 20574), -- 2605
(49714, 4340, 13, 0, 0, 1, 20574), -- 4340
(49714, 4341, 14, 0, 0, 1, 20574), -- 4341
(49714, 6261, 15, 0, 0, 1, 20574), -- 6261
(49714, 4342, 16, 0, 0, 1, 20574), -- 4342
(49714, 10290, 17, 0, 0, 1, 20574), -- 10290
-- 50458
(50458, 38682, 925, 0, 0, 1, 20574), -- 38682
(50458, 6217, 926, 0, 0, 1, 20574), -- 6217
(50458, 10940, 927, 3, 0, 1, 20574), -- 10940
(50458, 10938, 928, 2, 0, 1, 20574), -- 10938
(50458, 4470, 929, 0, 0, 1, 20574), -- 4470
(50458, 11291, 930, 0, 0, 1, 20574), -- 11291
-- 49723
(49723, 2528, 1, 0, 0, 1, 20574), -- 2528
(49723, 2529, 2, 0, 0, 1, 20574), -- 2529
(49723, 2530, 3, 0, 0, 1, 20574), -- 2530
(49723, 2531, 4, 0, 0, 1, 20574), -- 2531
(49723, 2532, 5, 0, 0, 1, 20574), -- 2532
(49723, 2533, 6, 0, 0, 1, 20574), -- 2533
(49723, 2534, 7, 0, 0, 1, 20574), -- 2534
(49723, 2535, 8, 0, 0, 1, 20574); -- 2535