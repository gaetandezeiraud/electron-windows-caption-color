{
  "targets": [
    {
      "target_name": "windowscaptioncolor",
      "sources": [
        "src/Init.cpp"
      ],      
      "include_dirs": [
        "include",
        "<!(node -e \"require('nan')\")"
      ]     
    }
  ]
}