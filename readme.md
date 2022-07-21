### Attribute Parser
lex()でToken作って、tokensにpush_backして、その上でparser

<tag-name attribute1-name = "value1" attribute2-name = "value2" ...> あり
The tags may also be nested.ただ、Examlpleを読むと<tag1 > /n <tag2 >でtag1.tag2.tag3~nameの形態のことを言っているので<tag1 ... tag2>はなさそう

If there are no attributes there is no space after tag name. オープニングタグのみのケースあり

All tag names are unique and the HRML source program is logically correct, i.e. valid nesting.
A tag can may have no attributes.
```text
Sample Input

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value
Sample Output

Name1
Not Found!
HelloWorld
```
tagはこちら
<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>

query(example)
tag1.tag2.tag3~name   "Not Found!"
tag2にはnameあり。ただ、tag3にはname無し。この場合not foundとなる。
1. ~で前後分割
2. 前のタグパートの最後のタグを探す
3. このタグのvalueに後ろパートがあればその値。なければNot Found


pair<string name, string value> attr;
vector<attr> attrs;
pair<string tag, vector<atr>> tag;
vector<tag> tags;

1. check and erase the first charcter and the last character
2. split with spaces
   1. the first element is the tag. 
   2. for loop
        make the paif of name and value
        push_back to attrs
   3. make pair of tag and the vector of attrs
   4. push_back the pair to the tags

