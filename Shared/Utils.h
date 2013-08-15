#pragma once

template <typename Type, int Size, int RequiredSize>
struct TypeSizeCheck;

template <typename Type, int Size>
struct TypeSizeCheck<Type, Size, Size>
{};

#define UniqueSizeCheckName2(c) TypeSizeCheck__##c
#define UniqueSizeCheckName1(c) UniqueSizeCheckName2(c)
#define UniqueSizeCheckName     UniqueSizeCheckName1(__COUNTER__)

#define CompileTimeSizeCheck(Type, Size)									\
	struct UniqueSizeCheckName : TypeSizeCheck<Type, sizeof(Type), Size>	\
	{}

template <typename Type, typename Member, int Offset, int RequiredOffset>
struct MemberOffsetCheck;

template <typename Type, typename Member, int Offset>
struct MemberOffsetCheck<Type, Member, Offset, Offset>
{};

#define CompileTimeOffsetCheck(Type, Member, Offset)								\
	typedef size_t Type##__##Member##__;											\
	struct Type##__##Member##__OffsetCheck :										\
	MemberOffsetCheck<Type, Type##__##Member##__, offsetof(Type, Member), Offset>	\
	{}