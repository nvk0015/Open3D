// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018-2021 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include "open3d/data/Extract.h"

#include "open3d/utility/FileSystem.h"
#include "open3d/utility/Helper.h"
#include "open3d/utility/Logging.h"
#include "tests/Tests.h"

namespace open3d {
namespace tests {

TEST(Extract, ExtractFromZIP) {
    std::string file_path = utility::GetDataPathCommon("test_data_00.zip");
    std::string extract_dir = utility::GetDataPathCommon();

    // Extract the test zip file.
    EXPECT_TRUE(data::Extract(file_path, extract_dir, "", true));
    std::string extracted_folder = extract_dir + "/test_data";
    std::string output_file = extracted_folder + "/lena_color.jpg";

    // Check if the extracted file exists.
    EXPECT_TRUE(utility::filesystem::FileExists(output_file));

    // Delete test file.
    std::remove(output_file.c_str());
    utility::filesystem::DeleteDirectory(extracted_folder);

    // Currently only `.zip` files are supported.
    EXPECT_FALSE(
            data::Extract(utility::GetDataPathCommon("test_data_00.tar.xy"),
                          extract_dir, "", true));
}

TEST(Extract, ExtractFromLargeZIP) {
    std::string file_path = "/home/rey/Downloads/test_large_data.zip";
    std::string extract_dir = "/home/rey/";
    EXPECT_TRUE(data::Extract(file_path, extract_dir, "", true));
}

}  // namespace tests
}  // namespace open3d
