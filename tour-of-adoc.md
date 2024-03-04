---
title: Tour of Asciidoc
author: Kong Giok
---

# 誤打誤撞的Asciidoc之旅  #

##  Settings  ##

### VSCode Settings ###

```json
"asciidoc.pdf.asciidoctorPdfCommandArgs": [
  "-a",
  "scripts=cjk",
  "-a",
  "pdf-theme=cjk",
  "-r",
  "asciidoctor-diagram",
  "-r",
  "asciidoctor-mathematical",
  "-a",
  "mathematical-format=svg",
  "-a",
  "mathematical-ppi=600",
],
"asciidoc.pdf.asciidoctorPdfCommandPath": "PATHTO_MY_HOME/.rvm/gems/ruby-3.3.0/bin/asciidoctor-pdf",
"terminal.integrated.env.osx": {
    "PATH": "PATHTO_MY_HOME/.rvm/gems/ruby-3.3.0/bin:PATHTO_MY_HOME/.rvm/gems/ruby-3.3.0@global/bin:PATHTO_MY_HOME/.rvm/rubies/ruby-3.3.0/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:PATHTO_MY_HOME/.rvm/bin",
    "GEM_HOME": "PATHTO_MY_HOME/.rvm/gems/ruby-3.3.0",
    "GEM_PATH": "PATHTO_MY_HOME/.rvm/gems/ruby-3.3.0:PATHTO_MY_HOME/.rvm/gems/ruby-3.3.0@global"
}
```