#include <gtest/gtest.h>

#include "downstream_src_a/downstream_src_a.hpp"

TEST(DownstreamSrcA, LabelsThroughTheWholeChain)
{
  EXPECT_EQ(
    "demo: elements=2",
    downstream_src_a::label_from_yaml("name: demo\nxml: \"<a><b/></a>\"\n"));
}

TEST(DownstreamSrcA, InvalidXmlPayload)
{
  EXPECT_EQ(
    "demo: invalid",
    downstream_src_a::label_from_yaml("name: demo\nxml: \"<a>\"\n"));
}

TEST(DownstreamSrcA, MissingKeyIsInvalid)
{
  EXPECT_EQ("invalid", downstream_src_a::label_from_yaml("name: demo\n"));
}

TEST(DownstreamSrcA, MalformedYamlIsInvalid)
{
  EXPECT_EQ("invalid", downstream_src_a::label_from_yaml("name: [unclosed\n"));
}

TEST(DownstreamSrcA, NestedValuesAreIgnored)
{
  EXPECT_EQ(
    "demo: elements=1",
    downstream_src_a::label_from_yaml(
      "extra: {nested: 1}\nname: demo\nxml: \"<a/>\"\n"));
}
