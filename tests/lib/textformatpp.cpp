// MIT License, Copyright (c) 2018 Philip Mayer <philip.mayer@shadowsith.de>
#include "textformatpp.h"
#include <string>

namespace text {

    // foreground colors----------------------------------------------
    
    std::string black(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Fg::BLACK + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Fg::BLACK + text + Format::END;
        return text;
    }

    std::string red(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Fg::RED + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Fg::RED + text + Format::END;
        return text;
    }

    std::string green(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Fg::GREEN + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Fg::GREEN + text + Format::END;
        return text;
    }

    std::string yellow(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Fg::YELLOW + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Fg::YELLOW + text + Format::END;
        return text;
    }

    std::string blue(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Fg::BLUE + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Fg::BLUE + text + Format::END;
        return text;
    }

    std::string magenta(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Fg::MAGENTA + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Fg::MAGENTA + text + Format::END;
        return text;
    }

    std::string cyan(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Fg::CYAN + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Fg::CYAN + text + Format::END;
        return text;
    }

    std::string white(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Fg::WHITE + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Fg::WHITE + text + Format::END;
        return text;
    }

    // background colors----------------------------------------------

    std::string black_bg(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Bg::BLACK + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Bg::BLACK + text + Format::END;
        return text;
    }

    std::string red_bg(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Bg::RED + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Bg::RED + text + Format::END;
        return text;
    }

    std::string green_bg(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Bg::GREEN + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Bg::GREEN + text + Format::END;
        return text;
    }

    std::string yellow_bg(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Bg::YELLOW + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Bg::YELLOW + text + Format::END;
        return text;
    }

    std::string blue_bg(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Bg::BLUE + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Bg::BLUE + text + Format::END;
        return text;
    }

    std::string magenta_bg(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Bg::MAGENTA + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Bg::MAGENTA + text + Format::END;
        return text;
    }

    std::string cyan_bg(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Bg::CYAN + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Bg::CYAN + text + Format::END;
        return text;
    }

    std::string white_bg(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Color::Bg::WHITE + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Color::Bg::WHITE + text + Format::END;
        return text;
    }

    // formatting-----------------------------------------------------

    std::string bold(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Format::Text::BOLD + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Format::Text::BOLD + text + Format::END; 
        return text;
    }
    
    std::string disable_multiline() {
        return Format::END;
    }

    std::string inverse(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Format::Text::INVERSE + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Format::Text::INVERSE + text + Format::END; 
        return text;
    }

    std::string underline(std::string text, bool multiline) {
        if(multiline == true)
            text = Format::BEGIN + Format::Text::UNDERLINE + text + Format::MULTILINE_END;
        else
            text = Format::BEGIN + Format::Text::UNDERLINE + text + Format::END; 
        return text;
    }
}
