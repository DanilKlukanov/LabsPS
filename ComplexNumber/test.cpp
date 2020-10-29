#include "pch.h"
#include <fstream>
TEST(UnitTest_initialization, in_A) {
	complex_numbers a(1.3, 7.8);
	string number_one = "13/10";
	string number_two = "39/5";
	ASSERT_EQ(a.get_real().GetDec(), number_one);
	ASSERT_EQ(a.get_imag().GetDec(), number_two);
}
TEST(UnitTest_initialization, in_B) {
	complex_numbers a(8.4635, -0.8);
	string number_one = "16927/2000";
	string number_two = "-4/5";
	ASSERT_EQ(a.get_real().GetDec(), number_one);
	ASSERT_EQ(a.get_imag().GetDec(), number_two);
}
TEST(UnitTest_initialization, in_C) {
	complex_numbers a(-8.0005, 1.9011);
	string number_one = "-16001/2000";
	string number_two = "19011/10000";
	ASSERT_EQ(a.get_real().GetDec(), number_one);
	ASSERT_EQ(a.get_imag().GetDec(), number_two);
}
TEST(UnitTest_initialization, in_D) {
	complex_numbers a;
	a = 8;
	string number_one = "8/1";
	string number_two = "0/1";
	ASSERT_EQ(a.get_real().GetDec(), number_one);
	ASSERT_EQ(a.get_imag().GetDec(), number_two);
}
TEST(UnitTest_initialization, in_E) {
	complex_numbers a;
	a = 8;
	a = 3.003;
	string number_one = "3003/1000";
	string number_two = "0/1";
	ASSERT_EQ(a.get_real().GetDec(), number_one);
	ASSERT_EQ(a.get_imag().GetDec(), number_two);
}
TEST(UnitTest_initialization, in_F) {
	complex_numbers a;
	a = 0;
	a = 3.003;
	a = 4.5;
	a = 2;
	a = 111.009;
	string number_one = "111009/1000";
	string number_two = "0/1";
	ASSERT_EQ(a.get_real().GetDec(), number_one);
	ASSERT_EQ(a.get_imag().GetDec(), number_two);
}
TEST(UnitTest_initialization, in_G) {
	complex_numbers a = 3;
	string number_one = "3/1";
	string number_two = "0/1";
	ASSERT_EQ(a.get_real().GetDec(), number_one);
	ASSERT_EQ(a.get_imag().GetDec(), number_two);
}
TEST(UnitTest_initialization, in_H) {
	complex_numbers a = 0;
	string number_one = "0/1";
	string number_two = "0/1";
	ASSERT_EQ(a.get_real().GetDec(), number_one);
	ASSERT_EQ(a.get_imag().GetDec(), number_two);
}
TEST(UnitTest_initialization, in_I) {
	complex_numbers a = 0.5;
	string number_one = "1/2";
	string number_two = "0/1";
	ASSERT_EQ(a.get_real().GetDec(), number_one);
	ASSERT_EQ(a.get_imag().GetDec(), number_two);
}
TEST(UnitTest_initialization, in_J) {
	complex_numbers a = 1.00005;
	string number_one = "20001/20000";
	string number_two = "0/1";
	ASSERT_EQ(a.get_real().GetDec(), number_one);
	ASSERT_EQ(a.get_imag().GetDec(), number_two);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_plus, plus_A)
{
	complex_numbers a(1, 8);
	complex_numbers b(2, 3);
	complex_numbers c = a + b;
	string number_one = "3/1";
	string number_two = "11/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_plus, plus_B)
{
	complex_numbers a(0.88, -7);
	complex_numbers b(0, 4.5);
	complex_numbers c = a + b;
	string number_one = "22/25";
	string number_two = "-5/2";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_plus, plus_C)
{
	complex_numbers a(1.6, 2);
	complex_numbers b(1, 4.5);
	complex_numbers c = a + b + 10;
	string number_one = "63/5";
	string number_two = "13/2";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_plus, plus_D)
{
	complex_numbers a(1.6, 2);
	complex_numbers b(1, 4.5);
	complex_numbers c = a + b + 10;
	c += a;
	string number_one = "71/5";
	string number_two = "17/2";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_plus, plus_E)
{
	complex_numbers a(2.0005, 2.009);
	complex_numbers b(7, 4.53);
	b += a;
	string number_one = "18001/2000";
	string number_two = "653900/100000";
	ASSERT_EQ(b.get_real().GetDec(), number_one);
	ASSERT_EQ(b.get_imag().GetDec(), number_two);
}
TEST(UnitTest_plus, plus_F)
{
	complex_numbers a(0, 0);
	complex_numbers b(10, 5.5);
	b += a;
	string number_one = "10/1";
	string number_two = "11/2";
	ASSERT_EQ(b.get_real().GetDec(), number_one);
	ASSERT_EQ(b.get_imag().GetDec(), number_two);
}
TEST(UnitTest_plus, plus_G)
{
	complex_numbers a(11, 4);
	complex_numbers b(10, 5);
	b += a + 3;
	string number_one = "24/1";
	string number_two = "9/1";
	ASSERT_EQ(b.get_real().GetDec(), number_one);
	ASSERT_EQ(b.get_imag().GetDec(), number_two);
}
TEST(UnitTest_plus, plus_H)
{
	complex_numbers a(-1, 100);
	complex_numbers b(91, -5);
	b += a + 12.5;
	string number_one = "205/2";
	string number_two = "95/1";
	ASSERT_EQ(b.get_real().GetDec(), number_one);
	ASSERT_EQ(b.get_imag().GetDec(), number_two);
}
TEST(UnitTest_plus, plus_I)
{
	complex_numbers a(-1.09, 100.546);
	complex_numbers b(89.33, -56.99);
	b += a + 108.104;
	string number_one = "245430000/1250000";
	string number_two = "2177800/50000";
	ASSERT_EQ(b.get_real().GetDec(), number_one);
	ASSERT_EQ(b.get_imag().GetDec(), number_two);
}
TEST(UnitTest_plus, plus_J)
{
	complex_numbers b(77.778, -81);
	b += 10;
	string number_one = "43889/500";
	string number_two = "-81/1";
	ASSERT_EQ(b.get_real().GetDec(), number_one);
	ASSERT_EQ(b.get_imag().GetDec(), number_two);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_mul, mul_A)
{
	complex_numbers a(10, 20);
	complex_numbers b(5, 9);
	complex_numbers c = a * b;
	string number_one = "-130/1";
	string number_two = "190/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_mul, mul_B)
{
	complex_numbers a(0.65, -1);
	complex_numbers b(0, 6.2);
	complex_numbers c = a * b;
	string number_one = "620/100";
	string number_two = "403/100";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_mul, mul_C)
{
	complex_numbers a(0.5, 3);
	complex_numbers b(25, 7.9);
	complex_numbers c = a * b * 7;
	string number_one = "-1568/20";
	string number_two = "11053/20";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_mul, mul_D)
{
	complex_numbers a(4.1234, 4);
	complex_numbers c(20, 6.6789);
	c *= a;
	string number_one = "2787620000/50000000";
	string number_two = "5376988813/50000000";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_mul, mul_E)
{
	complex_numbers a(0, 0);
	complex_numbers c(7, 2.789);
	c *= a;
	string number_one = "0/1000";
	string number_two = "0/1000";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_mul, mul_F)
{
	complex_numbers a(19.89, 4579);
	complex_numbers b(1099, 5.5);
	complex_numbers c(21, 10.6);
	complex_numbers d;
	d = a * b * c;
	string number_one = "-10682719075400/200000";
	string number_two = "21129157832200/200000";
	ASSERT_EQ(d.get_real().GetDec(), number_one);
	ASSERT_EQ(d.get_imag().GetDec(), number_two);
}
TEST(UnitTest_mul, mul_G)
{
	complex_numbers a(17, 2);
	complex_numbers b(3, 6);
	b *= a * 3;
	string number_one = "117/1";
	string number_two = "324/1";
	ASSERT_EQ(b.get_real().GetDec(), number_one);
	ASSERT_EQ(b.get_imag().GetDec(), number_two);
}
TEST(UnitTest_mul, mul_H)
{
	complex_numbers a(2, 10);
	complex_numbers b(-6, -55);
	b *= a * 0.5;
	string number_one = "538/2";
	string number_two = "-170/2";
	ASSERT_EQ(b.get_real().GetDec(), number_one);
	ASSERT_EQ(b.get_imag().GetDec(), number_two);
}
TEST(UnitTest_mul, mul_I)
{
	complex_numbers a(-0.7, 53.8);
	complex_numbers b(7.6, -20.01);
	b *= a * 2.99;
	string number_one = "40036772750000/12500000000";
	string number_two = "15805401625000/12500000000";
	ASSERT_EQ(b.get_real().GetDec(), number_one);
	ASSERT_EQ(b.get_imag().GetDec(), number_two);
}
TEST(UnitTest_mul, mul_J)
{
	complex_numbers b(90, -8.35);
	b *= 98;
	string number_one = "176400/20";
	string number_two = "-16366/20";
	ASSERT_EQ(b.get_real().GetDec(), number_one);
	ASSERT_EQ(b.get_imag().GetDec(), number_two);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_minus, min_A)
{
	complex_numbers a(8, 15);
	complex_numbers b(1, 40);
	complex_numbers c = a - b;
	string number_one = "7/1";
	string number_two = "-25/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_minus, min_B)
{
	complex_numbers a(1.9, -2);
	complex_numbers b(6, 8.9);
	complex_numbers c = a - b;
	string number_one = "-41/10";
	string number_two = "-109/10";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_minus, min_C)
{
	complex_numbers a(7.5, 70);
	complex_numbers b(41, 2.3);
	complex_numbers c = a - b - 80;
	string number_one = "-227/2";
	string number_two = "677/10";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_minus, min_D)
{
	complex_numbers a(9.7, 4);
	complex_numbers c(20, 5);
	c -= a;
	string number_one = "103/10";
	string number_two = "1/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_minus, min_E)
{
	complex_numbers a(10.8, 0.89);
	complex_numbers c(7, 10);
	c -= a;
	string number_one = "-19/5";
	string number_two = "911/100";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_minus, min_F)
{
	complex_numbers a(80.7, 49);
	complex_numbers b(19, 0.9);
	complex_numbers c(68.5, 100);
	complex_numbers d;
	d = a - b - c;
	string number_one = "-136/20";
	string number_two = "-519/10";
	ASSERT_EQ(d.get_real().GetDec(), number_one);
	ASSERT_EQ(d.get_imag().GetDec(), number_two);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_unary_minus, una_A)
{
	complex_numbers a(7, 10);
	complex_numbers c = -a;
	string number_one = "-7/1";
	string number_two = "-10/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_unary_minus, una_B)
{
	complex_numbers a(2.9, -6);
	complex_numbers c = -a;
	string number_one = "-29/10";
	string number_two = "6/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_det, det_A)
{
	complex_numbers a(90, 37);
	complex_numbers b(7, 20);
	complex_numbers c = a / b;
	string number_one = "1370/449";
	string number_two = "-1541/449";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_det, det_B)
{
	complex_numbers a(74, -6.82);
	complex_numbers b(81, 7.6);
	complex_numbers c = a / b;
	string number_one = "37138550/41367250";
	string number_two = "-6967625/41367250";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_det, det_C)
{
	complex_numbers a(7, 78);
	complex_numbers b(34, 5);
	complex_numbers c = a / b / 80;
	string number_one = "50240/7558400";
	string number_two = "209360/7558400";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_det, det_D)
{
	complex_numbers a(6.5, 9.6);
	complex_numbers c(20.8, 5);
	c /= a;
	string number_one = "916000/672050";
	string number_two = "-835900/672050";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_det, det_E)
{
	complex_numbers a(2.008, 23);
	complex_numbers b(90, 4.9);
	complex_numbers c(78.4, 50);
	complex_numbers d;
	d = a / b / c;
	string number_one = "-6466099126909560192/6506794624772273152";
	string number_two = "3377959885584736256/6506794624772273152";
	ASSERT_EQ(d.get_real().GetDec(), number_one);
	ASSERT_EQ(d.get_imag().GetDec(), number_two);
}
TEST(UnitTest_det, det_F)
{
	complex_numbers a(2.008, 23);
	complex_numbers c(0, 0);
	complex_numbers d;
	d = a / c;
	string number_one = "0/1";
	string number_two = "0/1";
	ASSERT_EQ(d.get_real().GetDec(), number_one);
	ASSERT_EQ(d.get_imag().GetDec(), number_two);
}
TEST(UnitTest_det, det_G)
{
	complex_numbers a(2.008, 23);
	complex_numbers d;
	d = a / 0;
	string number_one = "0/1";
	string number_two = "0/1";
	ASSERT_EQ(d.get_real().GetDec(), number_one);
	ASSERT_EQ(d.get_imag().GetDec(), number_two);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_equal, una_A)
{
	complex_numbers a(7, 10);
	complex_numbers c = -a;
	string number_one = "-7/1";
	string number_two = "-10/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
	ASSERT_TRUE(a == -c);
}
TEST(UnitTest_equal, una_B)
{
	complex_numbers a(2.9, -6);
	complex_numbers c = -a;
	string number_one = "-29/10";
	string number_two = "6/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
	ASSERT_TRUE(a == -c);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_unequal, une_A)
{
	complex_numbers a(7, 10);
	complex_numbers c = -a;
	string number_one = "-7/1";
	string number_two = "-10/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
	ASSERT_TRUE(a != c);
}
TEST(UnitTest_unequal, une_B)
{
	complex_numbers a(2.9, -6);
	complex_numbers c = -a;
	string number_one = "-29/10";
	string number_two = "6/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
	ASSERT_TRUE(a != c);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_abs, abs_A)
{
	complex_numbers a(7, 10);
	ASSERT_TRUE(a.Abs() == sqrt(pow(7, 2) + pow(10, 2)));
}
TEST(UnitTest_abs, abs_B)
{
	complex_numbers a(0.33, 0.17);
	ASSERT_TRUE(a.Abs() == sqrt(pow(0.33, 2) + pow(0.17, 2)));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_pow, pow_A)
{
	complex_numbers a(0.56, 1.1234);
	complex_numbers c = a.Pow();
	string number_one = "-14819180625/15625000000";
	string number_two = "157276/125000";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_pow, pow_B)
{
	complex_numbers a(7, 13);
	complex_numbers c = a.Pow(3);
	string number_one = "-3206/1";
	string number_two = "-286/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_pow, pow_C)
{
	complex_numbers a(-15, -78);
	complex_numbers c = a.Pow();
	string number_one = "-5859/1";
	string number_two = "2340/1";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}
TEST(UnitTest_pow, pow_D)
{
	complex_numbers a(1.34, 5.5);
	complex_numbers c = a.Pow(3);
	string number_one = "-11919889600/100000000";
	string number_two = "-13674760000/100000000";
	ASSERT_EQ(c.get_real().GetDec(), number_one);
	ASSERT_EQ(c.get_imag().GetDec(), number_two);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_arg, arg_A)
{
	complex_numbers a(6, 8);
	rational_numbers c = a.Arg();
	string number_one = "185459/200000";
	ASSERT_EQ(c.get_ratioanl_number(), number_one);
}
TEST(UnitTest_arg, arg_B)
{
	complex_numbers a(22.5, 6);
	rational_numbers c = a.Arg();
	string number_one = "66563/250000";
	ASSERT_EQ(c.get_ratioanl_number(), number_one);
}
TEST(UnitTest_arg, arg_C)
{
	complex_numbers a(1.1234, 8.23);
	rational_numbers c = a.Arg();
	string number_one = "36161/25000";
	ASSERT_EQ(c.get_ratioanl_number(), number_one);
}
TEST(UnitTest_arg, arg_D)
{
	complex_numbers a(-9, 0);
	rational_numbers c = a.Arg();
	string number_one = "314159/100000";
	ASSERT_EQ(c.get_ratioanl_number(), number_one);
}
TEST(UnitTest_arg, arg_E)
{
	complex_numbers a(-1.5, -6.7);
	rational_numbers c = a.Arg();
	string number_one = "-86797/50000";
	ASSERT_EQ(c.get_ratioanl_number(), number_one);
}
TEST(UnitTest_arg, arg_F)
{
	complex_numbers a(0, 7.8);
	rational_numbers c = a.Arg();
	string number_one = "15707/10000";
	ASSERT_EQ(c.get_ratioanl_number(), number_one);
}
TEST(UnitTest_arg, arg_G)
{
	complex_numbers a(0, -2.68);
	rational_numbers c = a.Arg();
	string number_one = "-15707/10000";
	ASSERT_EQ(c.get_ratioanl_number(), number_one);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UnitTest_out, out_A) {
	ofstream fout("complex_test.txt");
	ASSERT_TRUE(fout.is_open());

	complex_numbers a(1.1234, 56.56);
	fout << a << endl;
	fout << endl;

	complex_numbers b;
	fout << b << endl;
	fout << endl;

	complex_numbers c;
	c.set_real(24.121);
	c.set_imag(0);

	fout << c << endl;
}