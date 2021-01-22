template <>
std::vector<test_case<float>> make_test_cases<mtk::chopfp::RN, float>() {
	std::vector<test_case<float>> test_cases;
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		0
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		100
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'1000000000000u,
		0b0'01111111'0000000010'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'0000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000000'1000000000000u,
		0b0'01111111'0000000000'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'1111111111'1000000000000u,
		0b0'10000000'0000000000'0000000000000u,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<float>> make_test_cases<mtk::chopfp::RN_01, float>() {
	std::vector<test_case<float>> test_cases;
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		0
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		100
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'1000000000000u,
		0b0'01111111'0000000010'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'0000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000000'1000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'1111111111'1000000000000u,
		0b0'10000000'0000000000'0000000000000u,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<float>> make_test_cases<mtk::chopfp::RZ, float>() {
	std::vector<test_case<float>> test_cases;
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		0
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		100
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'1000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'0000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000000'1000000000000u,
		0b0'01111111'0000000000'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'1111111111'1000000000000u,
		0b0'01111111'1111111111'0000000000000u,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<float>> make_test_cases<mtk::chopfp::RU, float>() {
	std::vector<test_case<float>> test_cases;
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		0
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		100
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000000'0000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'1111111111'0000000000000u,
		0b0'10000000'0000000000'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b1'01111111'0000000000'0000000000000u,
		0b1'01111111'0000000000'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b1'01111111'1111111111'0000000000000u,
		0b1'01111111'1111111111'0000000000000u,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<float>> make_test_cases<mtk::chopfp::RD, float>() {
	std::vector<test_case<float>> test_cases;
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		0
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		100
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000000'0000000000000u,
		0b0'01111111'0000000000'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'1111111111'0000000000000u,
		0b0'01111111'1111111111'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b1'01111111'0000000000'0000000000000u,
		0b1'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b1'01111111'1111111111'0000000000000u,
		0b1'10000000'0000000000'0000000000000u,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<float>> make_test_cases<mtk::chopfp::SR_1, float>() {
	std::vector<test_case<float>> test_cases;
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		0
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		100
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'1000000000000u,
		0b0'01111111'0000000010'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'0000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000000'1000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'1111111111'1000000000000u,
		0b0'10000000'0000000000'0000000000000u,
		10
	});

	return test_cases;
}
