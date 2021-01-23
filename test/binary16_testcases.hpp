template <>
std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> make_test_cases<mtk::chopfp::RN, CHOPFP_BINARY16_TYPENAME>() {
	std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> test_cases;
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		0
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		100
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000001'10,
		0b0'01111'00000010'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000001'00,
		0b0'01111'00000001'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000000'10,
		0b0'01111'00000000'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'11111111'10,
		0b0'10000'00000000'00,
		8
	});

	return test_cases;
}

template <>
std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> make_test_cases<mtk::chopfp::RN_01, CHOPFP_BINARY16_TYPENAME>() {
	std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> test_cases;
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		0
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		100
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000001'10,
		0b0'01111'00000010'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000001'00,
		0b0'01111'00000001'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000000'10,
		0b0'01111'00000001'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'11111111'10,
		0b0'10000'00000000'00,
		8
	});

	return test_cases;
}

template <>
std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> make_test_cases<mtk::chopfp::RZ, CHOPFP_BINARY16_TYPENAME>() {
	std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> test_cases;
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		0
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		100
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000001'10,
		0b0'01111'00000001'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000001'00,
		0b0'01111'00000001'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000000'10,
		0b0'01111'00000000'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'11111111'10,
		0b0'01111'11111111'00,
		8
	});

	return test_cases;
}

template <>
std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> make_test_cases<mtk::chopfp::RU, CHOPFP_BINARY16_TYPENAME>() {
	std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> test_cases;
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		0
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		100
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000000'00,
		0b0'01111'00000001'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'11111111'00,
		0b0'10000'00000000'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b1'01111'00000000'00,
		0b1'01111'00000000'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b1'01111'11111111'00,
		0b1'01111'11111111'00,
		8
	});

	return test_cases;
}

template <>
std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> make_test_cases<mtk::chopfp::RD, CHOPFP_BINARY16_TYPENAME>() {
	std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> test_cases;
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		0
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		100
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000000'00,
		0b0'01111'00000000'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'11111111'00,
		0b0'01111'11111111'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b1'01111'00000000'00,
		0b1'01111'00000001'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b1'01111'11111111'00,
		0b1'10000'00000000'00,
		8
	});

	return test_cases;
}

template <>
std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> make_test_cases<mtk::chopfp::SR_1, CHOPFP_BINARY16_TYPENAME>() {
	std::vector<test_case<CHOPFP_BINARY16_TYPENAME>> test_cases;
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		0
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'0000000000u,
		0b0'01111'0000000000u,
		100
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000001'10,
		0b0'01111'00000010'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000001'00,
		0b0'01111'00000001'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'00000000'10,
		0b0'01111'00000001'00,
		8
	});
	test_cases.push_back(test_case<CHOPFP_BINARY16_TYPENAME>{
		0b0'01111'11111111'10,
		0b0'10000'00000000'00,
		8
	});

	return test_cases;
}
