/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CStringClass::CStringClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CStringClass::~CStringClass()
    {
        
    }

    /*static*/ int CStringClass::strcmp(ScriptObject* self, Stringp s1, Stringp s2)
    {
        Toplevel* toplevel = self->toplevel();

        if( !s1 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s1");
        }

        if( !s2 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s2");
        }
        
        StUTF8String s1UTF8(s1);
        StUTF8String s2UTF8(s2);
        return VMPI_strcmp( s1UTF8.c_str(), s2UTF8.c_str() );
    }

    /*static*/ int CStringClass::strcoll(ScriptObject* self, Stringp s1, Stringp s2)
    {
        Toplevel* toplevel = self->toplevel();

        if( !s1 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s1");
        }

        if( !s2 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s2");
        }
        
        StUTF8String s1UTF8(s1);
        StUTF8String s2UTF8(s2);
        return VMPI_strcoll( s1UTF8.c_str(), s2UTF8.c_str() );
    }

    /*static*/ Stringp CStringClass::strerror(ScriptObject* self, int errnum)
    {
        AvmCore *core = self->core();

        return core->newStringUTF8( VMPI_strerror( errnum ) );
    }

    /*static unsigned CStringClass::strlen(ScriptObject* self, Stringp str)
    {
        Toplevel* toplevel = self->toplevel();

        if( !str )
        {
            toplevel->throwArgumentError(kNullArgumentError, "str");
        }
        
        StUTF8String strUTF8(str);
        return (unsigned)VMPI_strlen( strUTF8.c_str() );
    }*/

    /*static*/ int CStringClass::strspn(ScriptObject* self, Stringp s1, Stringp s2)
    {
        Toplevel* toplevel = self->toplevel();

        if( !s1 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s1");
        }

        if( !s2 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s2");
        }
        
        StUTF8String s1UTF8(s1);
        StUTF8String s2UTF8(s2);
        return VMPI_strspn( s1UTF8.c_str(), s2UTF8.c_str() );
    }
    

}
