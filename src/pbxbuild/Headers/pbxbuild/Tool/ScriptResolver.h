/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree.
 */

#ifndef __pbxbuild_Tool_ScriptResolver_h
#define __pbxbuild_Tool_ScriptResolver_h

#include <pbxbuild/Tool/Invocation.h>
#include <pbxbuild/Target/BuildRules.h>
#include <pbxbuild/Tool/Input.h>

namespace pbxbuild {
namespace Tool {

class Context;

class ScriptResolver {
private:
    pbxspec::PBX::Tool::shared_ptr _tool;

private:
    explicit ScriptResolver(pbxspec::PBX::Tool::shared_ptr const &tool);

public:
    void resolve(
        Tool::Context *toolContext,
        pbxsetting::Environment const &environment,
        pbxproj::PBX::LegacyTarget::shared_ptr const &legacyTarget) const;
    void resolve(
        Tool::Context *toolContext,
        pbxsetting::Environment const &environment,
        pbxproj::PBX::ShellScriptBuildPhase::shared_ptr const &buildPhase) const;
    void resolve(
        Tool::Context *toolContext,
        pbxsetting::Environment const &environment,
        Tool::Input const &file) const;

public:
    pbxspec::PBX::Tool::shared_ptr const &tool() const
    { return _tool; }

public:
    static std::string ToolIdentifier()
    { return "com.apple.commands.shell-script"; }

public:
    static std::unique_ptr<ScriptResolver>
    Create(pbxspec::Manager::shared_ptr const &specManager, std::vector<std::string> const &specDomains);
};

}
}

#endif // !__pbxbuild_Tool_ScriptResolver_h
