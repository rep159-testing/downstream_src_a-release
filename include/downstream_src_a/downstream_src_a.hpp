#ifndef DOWNSTREAM_SRC_A__DOWNSTREAM_SRC_A_HPP_
#define DOWNSTREAM_SRC_A__DOWNSTREAM_SRC_A_HPP_

#include <string>

namespace downstream_src_a
{

/// Label the `xml` value of a YAML mapping with its `name` value, through
/// upstream_c. "invalid" if the YAML does not parse or a key is missing.
std::string label_from_yaml(const std::string & document);

}  // namespace downstream_src_a

#endif  // DOWNSTREAM_SRC_A__DOWNSTREAM_SRC_A_HPP_
