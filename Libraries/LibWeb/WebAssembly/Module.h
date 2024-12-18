/*
 * Copyright (c) 2021, Ali Mohammad Pur <mpfard@serenityos.org>
 * Copyright (c) 2023, Tim Flynn <trflynn89@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGC/Ptr.h>
#include <LibGC/Root.h>
#include <LibJS/Forward.h>
#include <LibWasm/Types.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/PlatformObject.h>
#include <LibWeb/WebAssembly/WebAssembly.h>

namespace Web::WebAssembly {

class Module : public Bindings::PlatformObject {
    WEB_PLATFORM_OBJECT(Module, Bindings::PlatformObject);
    GC_DECLARE_ALLOCATOR(Module);

public:
    static WebIDL::ExceptionOr<GC::Ref<Module>> construct_impl(JS::Realm&, GC::Root<WebIDL::BufferSource>& bytes);

    NonnullRefPtr<Detail::CompiledWebAssemblyModule> compiled_module() const { return m_compiled_module; }

private:
    Module(JS::Realm&, NonnullRefPtr<Detail::CompiledWebAssemblyModule>);

    virtual void initialize(JS::Realm&) override;

    NonnullRefPtr<Detail::CompiledWebAssemblyModule> m_compiled_module;
};

}
