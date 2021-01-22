template <>
std::vector<test_case<double>> make_test_cases<mtk::chopfp::RN, double>() {
	std::vector<test_case<double>> test_cases;
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		100
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000001'100000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000010'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000'100000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'1111111111'100000000000000000000000000000000000000000lu,
		0b0'10000000000'0000000000'000000000000000000000000000000000000000000lu,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<double>> make_test_cases<mtk::chopfp::RN_01, double>() {
	std::vector<test_case<double>> test_cases;
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		100
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000001'100000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000010'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000'100000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'1111111111'100000000000000000000000000000000000000000lu,
		0b0'10000000000'0000000000'000000000000000000000000000000000000000000lu,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<double>> make_test_cases<mtk::chopfp::RZ, double>() {
	std::vector<test_case<double>> test_cases;
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		100
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000001'100000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000'100000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'1111111111'100000000000000000000000000000000000000000lu,
		0b0'01111111111'1111111111'000000000000000000000000000000000000000000lu,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<double>> make_test_cases<mtk::chopfp::RU, double>() {
	std::vector<test_case<double>> test_cases;
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		100
	});
	test_cases.push_back(test_case<double>{
		0b1'01111111111'0000000000'000000000000000000000000000000000000000000lu,
		0b1'01111111111'0000000000'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b1'01111111111'1111111111'000000000000000000000000000000000000000000lu,
		0b1'01111111111'1111111111'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000'000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'1111111111'000000000000000000000000000000000000000000lu,
		0b0'10000000000'0000000000'000000000000000000000000000000000000000000lu,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<double>> make_test_cases<mtk::chopfp::RD, double>() {
	std::vector<test_case<double>> test_cases;
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		100
	});
	test_cases.push_back(test_case<double>{
		0b1'01111111111'0000000000'000000000000000000000000000000000000000000lu,
		0b1'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b1'01111111111'1111111111'000000000000000000000000000000000000000000lu,
		0b1'10000000000'0000000000'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000'000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'1111111111'000000000000000000000000000000000000000000lu,
		0b0'01111111111'1111111111'000000000000000000000000000000000000000000lu,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<double>> make_test_cases<mtk::chopfp::SR_1, double>() {
	std::vector<test_case<double>> test_cases;
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		100
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000001'100000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000010'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000'100000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'1111111111'100000000000000000000000000000000000000000lu,
		0b0'10000000000'0000000000'000000000000000000000000000000000000000000lu,
		10
	});

	return test_cases;
}
