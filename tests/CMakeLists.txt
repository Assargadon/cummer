project("cummer-tests")


add_executable(test_digest.exe
	test_digest.cpp
)

add_executable(test_DigestTree.exe
	test_DigestTree.cpp
	../core/DigestTree.cpp ../core/DigestTree.h
)
